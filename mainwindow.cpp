#include "mainwindow.h"
#include "gamewindow.h"
#include <QPainter>
#include <QApplication>
#include <QScreen>
#include <QStyle>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QLabel>
#include "unitmenu.h"
#include "buildingmenu.h"
#include "pausemenu.h"
#include "infantery.h"
#include "ai.h"


MainWindow::MainWindow(Map *terrainMap,Map *unitMap,Cursor* cursor,int gameType) : cursor(cursor),centerZone(terrainMap,unitMap,cursor)
{
    cursorState=0;
    setCentralWidget(&centerZone);
    resizeTimer = new QTimer(this);
    connect(resizeTimer,SIGNAL(timeout()),this,SLOT(resizeTimeout()));
    QScreen *screen = QGuiApplication::primaryScreen();
    this->resize(screen->availableGeometry().width()/2,screen->availableGeometry().height()/2);
    move(screen->availableGeometry().center()-this->rect().center());
    switch(gameType)
    {
    case(1):
        reseau=false;
        break;
    case(2):
        reseau=true;
        break;
    case(3):
        inactiveAI=true;
        break;
    case(4):
        pathfindAI=true;
        break;
    }
    QObject::connect(&centerZone,SIGNAL(nextTurn()),this,SLOT(switchPlayer()));

    /*création du serveur? */
    if (reseau){
        server = new QTcpServer();
        if(! server->listen(QHostAddress::Any, 8123)) {
            std::cout << "I am a client" << std::endl;
            other = new QTcpSocket();
            connect(other, SIGNAL(connected()), this, SLOT(onConnected()));
            other->connectToHost("192.168.0.110", 8123);
            connect(other, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
            myTurn = true;
        }
        else {
            std::cout << "I am the server" << std::endl;
            other = nullptr;
            myTurn = false;
        }
        connect(server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
    }
}

void MainWindow::onNewConnection() {
    std::cout << "A new client is connecting !" << std::endl;
    other = server->nextPendingConnection();
    connect(other, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
    connect(other, SIGNAL(readyRead()), this, SLOT(onData()));
    QJsonObject config;
    config["income"] = 1000;
    config["map"] = 25087;
    config["firstplayer"] = 5;
    config["secondplayer"] = 10;
    config["youplay"] = "firstPlayer";
    QJsonObject unit1;
    unit1["country"] = 10;
    unit1["type"] = "infantry";
    unit1["x"] = 15;
    unit1["y"] = 3;
    config["units"] = unit1;
    sendJson(config);
    isConfigured = true;
}

void MainWindow::onDisconnected() {
    std::cout << "The other guy just disconnected" << std::endl;
}

void MainWindow::onConnected() {
    std::cout << "I am connected" << std::endl;
    connect(other, SIGNAL(readyRead()), this, SLOT(onData()));
}

void MainWindow::onData() {
    std::cout << "Some data !" << std::endl;
    if(currentSize == 0) {
        if(other->bytesAvailable() < 4)
            return;
        QDataStream in(other);
        in >> currentSize;
    }
    if(other->bytesAvailable() < currentSize)
        return;
    QByteArray data = other->read(currentSize);
    std::cout << data.toStdString() << std::endl;
    currentSize = 0;
    //conversion en QJsonObject
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject json = doc.object();

    if (!isConfigured){
        //les configuration sont comment on crée notre jeu de base, donc pour l'instant inutile
        isConfigured = true;
    }
    else {

        //Mouvement
        if ( json.contains("xM") || json.contains("yM") || json.contains("oldXM") || json.contains("oldYM") )
        {
            int oldX = json["xM"].toInt();
            int oldY = json["yM"].toInt();
            int newX = json["newXM"].toInt();
            int newY = json["newYM"].toInt();
            cursor->getPlayer()->getUnit(oldX,oldY)->move(newX,newY);
        }
        //Attaque
        if ( json.contains("XA") )
        {
            int x = json["XA"].toInt();
            int y = json["YA"].toInt();
            int fromX = json["fromXA"].toInt();
            int fromY = json["fromYA"].toInt();
            cursor->getPlayer()->getUnit(fromX,fromY)->attack(cursor->getOpponent()->getUnit(x,y));
        }
        //Capture
        if ( json.contains("XC") )
        {
            int x = json["XC"].toInt();
            int y = json["YC"].toInt();
            cursor->getPlayer()->getUnit(static_cast<unsigned int>(x),static_cast<unsigned int>(y))->capture();
        }
        //Construction
        if ( json.contains("XB") )
        {
            unsigned int x = json["XB"].toInt();
            unsigned int y = json["YB"].toInt();
            QString unit = json["type"].toString();
            if ( unit == "infantery"){
                cursor->getPlayer()->getBuilding(x,y)->createUnit(1);
            }
            else if ( unit == "bazooka"){
                cursor->getPlayer()->getBuilding(x,y)->createUnit(2);
            }
            else if ( unit == "recon"){
                cursor->getPlayer()->getBuilding(x,y)->createUnit(3);
            }
            else if ( unit == "antiair"){
                cursor->getPlayer()->getBuilding(x,y)->createUnit(4);
            }
            else if ( unit == "tank"){
                cursor->getPlayer()->getBuilding(x,y)->createUnit(5);
            }
            else if ( unit == "mdtank"){
                cursor->getPlayer()->getBuilding(x,y)->createUnit(6);
            }
            else if ( unit == "megatank"){
                cursor->getPlayer()->getBuilding(x,y)->createUnit(7);
            }
            else if ( unit == "neotank"){
                cursor->getPlayer()->getBuilding(x,y)->createUnit(8);
            }
            else if ( unit == "bcopter"){
                cursor->getPlayer()->getBuilding(x,y)->createUnit(1);
            }
            else if ( unit == "fighter"){
                cursor->getPlayer()->getBuilding(x,y)->createUnit(2);
            }
            else if ( unit == "bomber"){
                cursor->getPlayer()->getBuilding(x,y)->createUnit(3);
            }
        }
        //Fin de tour
        if ( json.contains("endofturn") )
        {
            bool fin = json["endofturn"].toBool();
            if (fin){ cursor->switchPlayerState();}
            myTurn = true;
        }
    }
}

void MainWindow::sendJson(QJsonObject obj) {
    QByteArray data = QJsonDocument(obj).toJson();
    QDataStream out(other);
    out << (quint32) data.length();
    other->write(data);
    std::cout << "Sending " << data.toStdString() << std::endl;
}

bool MainWindow::getPathfindAI() const
{
    return pathfindAI;
}

AI *MainWindow::getAI() const
{
    return ai;
}

void MainWindow::setAI(AI *value)
{
    ai = value;
    connect(this,SIGNAL(passedTurn()),ai,SLOT(play()));
}

bool MainWindow::getInactiveAI() const
{
    return ai;
}

void MainWindow::keyPressEvent(QKeyEvent * event){
    if (! myTurn){
        return;
    }
    if (event->key() == Qt::Key_Left){
        // faire bouger la case selectionnee vers la gauche
        if(cursorState == 0){
            cursor->move(0,1,0,0);
        }
        else if(cursorState==1 || cursorState==2){
            cursor->moveAlt(0,1,0,0);
        }
        updateWidget();
    }

    if (event->key() == Qt::Key_Right){
        if(cursorState == 0){
            cursor->move(0,0,0,1);
        }
        else if(cursorState==1 || cursorState==2){
            cursor->moveAlt(0,0,0,1);
        }
        updateWidget();
    }

    if (event->key() == Qt::Key_Up){
        // faire bouger la case ou l'option (dans un menu) selectionee
        if(cursorState == 0){
            cursor->move(1,0,0,0);
        }
        else if(cursorState==1 || cursorState==2){
            cursor->moveAlt(1,0,0,0);
        }
        updateWidget();
    }

    if (event->key() == Qt::Key_Down){
        if(cursorState==0){
            cursor->move(0,0,1,0);
        }
        else if(cursorState==1 || cursorState==2){
            cursor->moveAlt(0,0,1,0);
        }
        updateWidget();
    }

    if (event->key() == Qt::Key_Space){
        //confirmer la selection == bouton A
        if (cursor->unitOfPlayer()
            && cursorState == 0
            && cursor->getPlayer()->getUnit(cursor->getPosX(),cursor->getPosY())->getCanPlay())
        {
            UnitMenu *menu = new UnitMenu(cursor->getRealX(),cursor->getRealY(),typeOfUnitMenu(0));
            QObject::connect(menu,SIGNAL(moveUnit()),this,SLOT(movingUnit()));
            QObject::connect(menu,SIGNAL(attacking()),this,SLOT(unitAttack()));
            QObject::connect(menu,SIGNAL(capturing()),this,SLOT(unitCapture()));
            QObject::connect(menu,SIGNAL(waiting()),this,SLOT(setUnitWainting()));
            menu->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::Popup);
            menu->show();
        }
        else if((cursor->buildOfPlayer() == 35 || cursor->buildOfPlayer()==36)
                && cursorState == 0
                && !cursor->unitOfPlayer())
        {
            BuildingMenu *menu = new BuildingMenu(cursor->getRealX(), cursor->getRealY(),cursor->getPlayer()->getBuilding(cursor->getPosX(),cursor->getPosY()));
            QObject::connect(menu,SIGNAL(qMenuClose()),this,SLOT(updateWin()));
            QObject::connect(menu,SIGNAL(createU()),this,SLOT(createUnit()));
            menu->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::Popup);
            menu->show();
        }
        else if(cursorState == 1)
        {
            cursor->getPlayer()->getUnit(unitPosX, unitPosY)->move(cursor->getPosX(), cursor->getPosY());
            centerZone.movementsReset();
            cursorState = 0;

            if (reseau) {
                QJsonObject action;
                action["xM"] = unitPosX;
                action["yM"] = unitPosY;
                action["newXM"] = cursor->getPosX();
                action["newYM"] = cursor->getPosY();
                sendJson(action);
            }

            UnitMenu *menu = new UnitMenu(cursor->getRealX(), cursor->getRealY(), typeOfUnitMenu(1));
            menu->setEscape(false);
            QObject::connect(menu, SIGNAL(attacking()), this, SLOT(unitAttack()));
            QObject::connect(menu, SIGNAL(capturing()), this, SLOT(unitCapture()));
            QObject::connect(menu, SIGNAL(waiting()), this, SLOT(setUnitWainting()));
            menu->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
            menu->setFocus();
            menu->forceResp();
            menu->show();
        }
        else if(cursorState==2 && !cursor->unitOfPlayer())
        {
            cursor->getPlayer()->getUnit(unitPosX,unitPosY)->attack(cursor->getOpponent()->getUnit(cursor->getPosX(),cursor->getPosY()));
            centerZone.attackReset();

            if (reseau){
                QJsonObject action;
                action["XA"] = cursor->getPosX();
                action["YA"] = cursor->getPosY();
                action["fromXA"] = unitPosX;
                action["fromYA"] = unitPosY;
                sendJson(action);
            }

            cursorState=0;
        }
    }
    if (event->key() == Qt::Key_Escape){
    //retour == bouton B
        if(cursorState==1){
            centerZone.movementsReset();
            cursorState=0;
        }
        else if(cursorState==2)
        {
            centerZone.attackReset();
            cursorState=0;
        }
        else if(cursorState==0){
            PauseMenu *menu = new PauseMenu();
            menu->move(this->rect().center());
            QObject::connect(menu,SIGNAL(nextPlayer()),this,SLOT(switchPlayer()));
            menu->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::Popup);
            menu->show();
        }
    }
}

void MainWindow::mousePressEvent(QMouseEvent *ev){
    //confirmer la selection == bouton A
        cursor->setPosition(ev->x(),ev->y());
        update();
        if(cursor->unitOfPlayer() && cursorState==0 && cursor->getPlayer()->getUnit(cursor->getPosX(),cursor->getPosY())->getCanPlay())
        {
            UnitMenu *menu = new UnitMenu(cursor->getRealX(),cursor->getRealY(),typeOfUnitMenu(0));
            QObject::connect(menu,SIGNAL(moveUnit()),this,SLOT(movingUnit()));
            QObject::connect(menu,SIGNAL(attacking()),this,SLOT(unitAttack()));
            QObject::connect(menu,SIGNAL(capturing()),this,SLOT(unitCapture()));
            QObject::connect(menu,SIGNAL(waiting()),this,SLOT(setUnitWainting()));
            QObject::connect(menu,SIGNAL(menuClose()),this,SLOT(curState()));
            menu->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::Popup);
            menu->show();
        }
        else if((cursor->buildOfPlayer() == 35 || cursor->buildOfPlayer()==36) && cursorState==0 && !cursor->unitOfPlayer())
        {
            BuildingMenu *menu = new BuildingMenu(cursor->getRealX(),cursor->getRealY(),cursor->getPlayer()->getBuilding(cursor->getPosX(),cursor->getPosY()));
            QObject::connect(menu,SIGNAL(qMenuClose()),this,SLOT(updateWin()));
            QObject::connect(menu,SIGNAL(menuClose()),this,SLOT(curState()));
            QObject::connect(menu,SIGNAL(createU()),this,SLOT(createUnit()));
            menu->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::Popup);
            menu->show();
        }
        else if(cursorState==1 && cursor->canMoveUnit(cursor->getPosX(),cursor->getPosY()))
        {
            cursor->getPlayer()->getUnit(unitPosX,unitPosY)->move(cursor->getPosX(),cursor->getPosY());
            centerZone.movementsReset();
            cursorState=0;

            if (reseau){
                QJsonObject action;
                action["xM"] = unitPosX;
                action["yM"] = unitPosY;
                action["newXM"] = cursor->getPosX();
                action["newYM"] = cursor->getPosY();
                sendJson(action);
            }

            UnitMenu *menu = new UnitMenu(cursor->getRealX(),cursor->getRealY(),typeOfUnitMenu(1));
            QObject::connect(menu,SIGNAL(attacking()),this,SLOT(unitAttack()));
            QObject::connect(menu,SIGNAL(capturing()),this,SLOT(unitCapture()));
            QObject::connect(menu,SIGNAL(waiting()),this,SLOT(setUnitWainting()));
            QObject::connect(menu,SIGNAL(menuClose()),this,SLOT(curState()));
            menu->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
            this->setDisabled(true);
            menu->setFocus();
            menu->forceResp();
            menu->show();
        }
        else if(cursorState==2 && !cursor->unitOfPlayer() && cursor->canMoveUnit(cursor->getPosX(),cursor->getPosY()))
        {
            cursor->getPlayer()->getUnit(unitPosX,unitPosY)->attack(cursor->getOpponent()->getUnit(cursor->getPosX(),cursor->getPosY()));
            centerZone.attackReset();

            if (reseau){
                QJsonObject action;
                action["XA"] = cursor->getPosX();
                action["YA"] = cursor->getPosY();
                action["fromXA"] = unitPosX;
                action["fromYA"] = unitPosY;
                sendJson(action);
            }

            cursorState=0;
        }
        updateWidget();
}

void MainWindow::curState(){
    cursorState = 0;
}

GameWindow* MainWindow::getWidget()
{
    return &centerZone;
}

void MainWindow::updateWidget()
{
    centerZone.updateMap(cursor->getPlayer()->get_money(),cursor->getPlayerState());
}

void MainWindow::updateWin()
{
    updateWidget();
}

void MainWindow::movingUnit()
{
    unitPosX=cursor->getPosX();
    unitPosY=cursor->getPosY();
    vector<vector<int>> possibPos=cursor->getPlayer()->getUnit(static_cast<unsigned int>(unitPosX),static_cast<unsigned int>(unitPosY))->movePossib(cursor->getPosX(),cursor->getPosY());
    centerZone.setMovements(possibPos);
    cursor->updateMovements(possibPos);
    cursorState=1;
    this->setDisabled(false);
    updateWidget();
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    resizeTimer->stop();
    resizeTimer->start(RESIZE_TIMEOUT);
}

void MainWindow::switchPlayer()
{
    cursor->switchPlayerState();

    if (ai){
        emit passedTurn();
    }
    if (reseau){
        QJsonObject action;
        action["endofturn"] = true;
        sendJson(action);
        myTurn = false;
    }
    updateWidget();
}

void MainWindow::setUnitWainting()
{
    cursor->getPlayer()->getUnit(static_cast<unsigned int>(cursor->getPosX()),static_cast<unsigned int>(cursor->getPosY()))->wait();
    this->setDisabled(false);
    updateWidget();
}

void MainWindow::unitAttack()
{
    vector<vector<int>> possibPos = cursor->opponnentUnit();
    unitPosX=cursor->getPosX();
    unitPosY=cursor->getPosY();
    possibPos.push_back({unitPosX,unitPosY});
    centerZone.setAttack(possibPos);
    cursor->updateMovements(possibPos);
    cursorState=2;
    this->setDisabled(false);
    updateWidget();
}

void MainWindow::unitCapture()
{
    cursor->getPlayer()->getUnit(static_cast<unsigned int>(cursor->getPosX()),static_cast<unsigned int>(cursor->getPosY()))->capture();

    if (reseau){
        QJsonObject action;
        action["XC"] = cursor->getPosX();
        action["YC"] = cursor->getPosY();
        sendJson(action);
    }
    this->setDisabled(false);
    updateWidget();
}

void MainWindow::resizeTimeout()
{
    resizeTimer->stop();
    centerZone.setSize(this->width(),this->height());
    updateWidget();
}

int MainWindow::typeOfUnitMenu(int moveState)
{
    int state=0;
    if(moveState==0)
    {
        if(cursor->onABuilding() && !cursor->opponnentUnit().empty())
        {
            state=1;
        }
        else if(cursor->onABuilding())
        {
            state=2;
        }
        else if(!cursor->opponnentUnit().empty())
        {
            state=3;
        }
        else
        {
            state=4;
        }
    }
    else
    {
        if(cursor->onABuilding() && !cursor->opponnentUnit().empty())
        {
            state=5;
        }
        else if(cursor->onABuilding())
        {
            state=6;
        }
        else if(!cursor->opponnentUnit().empty())
        {
            state=7;
        }
        else
        {
            state=8;
        }
    }
    return state;
}

void MainWindow::createUnit(){
    cursorState = 0;
    if (reseau){
        int x = cursor->getPosX();
        int y = cursor->getPosY();
        if ( cursor->getUnitMap()->getElement(x,y) != 0){
            QJsonObject action;
            action["XB"] = x;
            action["YB"] = y;
            if ( cursor->getUnitMap()->getElement(x,y) == 50 ||cursor->getUnitMap()->getElement(x,y) == 61){
                action["type"] = "infantery";
            }
            else if ( cursor->getUnitMap()->getElement(x,y) == 51 ||cursor->getUnitMap()->getElement(x,y) == 62){
                action["type"] = "mdtank";
            }
            else if ( cursor->getUnitMap()->getElement(x,y) == 52 ||cursor->getUnitMap()->getElement(x,y) == 63){
                action["type"] = "megatank";
            }
            else if ( cursor->getUnitMap()->getElement(x,y) == 53 ||cursor->getUnitMap()->getElement(x,y) == 64){
                action["type"] = "neotank";
            }
            else if ( cursor->getUnitMap()->getElement(x,y) == 54 ||cursor->getUnitMap()->getElement(x,y) == 65){
                action["type"] = "recon";
            }
            else if ( cursor->getUnitMap()->getElement(x,y) == 55 ||cursor->getUnitMap()->getElement(x,y) == 66){
                action["type"] = "tank";
            }
            else if ( cursor->getUnitMap()->getElement(x,y) == 56 ||cursor->getUnitMap()->getElement(x,y) == 67){
                action["type"] = "fighter";
            }
            else if ( cursor->getUnitMap()->getElement(x,y) == 57 ||cursor->getUnitMap()->getElement(x,y) == 68){
                action["type"] = "bomber";
            }
            else if ( cursor->getUnitMap()->getElement(x,y) == 58 ||cursor->getUnitMap()->getElement(x,y) == 69){
                action["type"] = "bazooka";
            }
            else if ( cursor->getUnitMap()->getElement(x,y) == 59 ||cursor->getUnitMap()->getElement(x,y) == 70){
                action["type"] = "bcopter";
            }
            else if ( cursor->getUnitMap()->getElement(x,y) == 60 ||cursor->getUnitMap()->getElement(x,y) == 71){
                action["type"] = "antiair";
            }
            sendJson(action);
        }
    }
    updateWidget();
}
