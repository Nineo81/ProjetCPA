#include "mainwindow.h"
#include "gamewindow.h"
#include <QPainter>
#include <QApplication>
#include <QScreen>
#include <QStyle>
#include <QKeyEvent>
#include <QMouseEvent>
#include "unitmenu.h"
#include "buildingmenu.h"
#include "pausemenu.h"

MainWindow::MainWindow(Map *terrainMap,Map *unitMap,Cursor* cursor) : cursor(cursor),centerZone(terrainMap,unitMap,cursor)
{
    cursorState=0;
    setCentralWidget(&centerZone);
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    centerZone.setSize(screenGeometry.width()*0.9,screenGeometry.height()*0.9);
    this->adjustSize();
    move(screen->availableGeometry().center()-this->rect().center());

    /*création du serveur? */
    server = new QTcpServer();
    if(! server->listen(QHostAddress::Any, 8123)) {
        std::cout << "I am a client" << std::endl;
        other = new QTcpSocket();
        connect(other, SIGNAL(connected()), this, SLOT(onConnected()));
        other->connectToHost("127.0.0.1", 8123);
        connect(other, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
        }
    else {
        std::cout << "I am the server" << std::endl;
        other = nullptr;
        }
    connect(server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
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

    }
}

void MainWindow::sendJson(QJsonObject obj) {
    QByteArray data = QJsonDocument(obj).toJson();
    QDataStream out(other);
    out << (quint32) data.length();
    other->write(data);
    std::cout << "Sending " << data.toStdString() << std::endl;
}

void MainWindow::keyPressEvent(QKeyEvent * event){
     /* ça depend de comment on fait notre truc il me semble.*/
    if (event->key() == Qt::Key_Left){
    //faire bouger la case selectionnee vers la gauche
        if(cursorState==0){
            cursor->move(0,1,0,0);
        }
        else if(cursorState==1 || cursorState==2){
            cursor->moveAlt(0,1,0,0);
        }
        centerZone.updateMap();
    }
    if (event->key() == Qt::Key_Right){
        if(cursorState==0){
            cursor->move(0,0,0,1);
        }
        else if(cursorState==1 || cursorState==2){
            cursor->moveAlt(0,0,0,1);
        }
        centerZone.updateMap();
    }
    if (event->key() == Qt::Key_Up){
    //faire bouger la case ou l'option (dans un menu) selectionee
        if(cursorState==0){
            cursor->move(1,0,0,0);
        }
        else if(cursorState==1 || cursorState==2){
            cursor->moveAlt(1,0,0,0);
        }
        centerZone.updateMap();
    }
    if (event->key() == Qt::Key_Down){
        if(cursorState==0){
            cursor->move(0,0,1,0);
        }
        else if(cursorState==1 || cursorState==2){
            cursor->moveAlt(0,0,1,0);
        }
        centerZone.updateMap();
    }
    if (event->key() == Qt::Key_Space || event->key() == Qt::Key_Enter){
    //confirmer la selection == bouton A
        if(cursor->unitOfPlayer() && cursorState==0 && cursor->getPlayer()->getUnit(cursor->getPosX(),cursor->getPosY())->getCanPlay())
        {
            UnitMenu *menu = new UnitMenu(cursor->getRealX(),cursor->getRealY(),typeOfUnitMenu(0));
            QObject::connect(menu,SIGNAL(moveUnit()),this,SLOT(movingUnit()));
            QObject::connect(menu,SIGNAL(attacking()),this,SLOT(unitAttack()));
            QObject::connect(menu,SIGNAL(capturing()),this,SLOT(unitCapture()));
            QObject::connect(menu,SIGNAL(waiting()),this,SLOT(setUnitWainting()));
            menu->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
            menu->show();
        }
        else if(cursor->buildOfPlayer() == 35 && cursorState==0 && !cursor->unitOfPlayer())
        {
            BuildingMenu *menu = new BuildingMenu(cursor->getRealX(),cursor->getRealY(),cursor->getPlayer()->getBuilding(cursor->getPosX(),cursor->getPosY()));
            QObject::connect(menu,SIGNAL(qMenuClose()),this,SLOT(updateWin()));
            menu->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
            menu->show();
        }
        else if(cursorState==1)
        {
            cursor->getPlayer()->getUnit(unitPosX,unitPosY)->move(cursor->getPosX(),cursor->getPosY());
            centerZone.movementsReset();
            cursorState=0;
            UnitMenu *menu = new UnitMenu(cursor->getRealX(),cursor->getRealY(),typeOfUnitMenu(1));
            QObject::connect(menu,SIGNAL(attacking()),this,SLOT(unitAttack()));
            QObject::connect(menu,SIGNAL(capturing()),this,SLOT(unitCapture()));
            QObject::connect(menu,SIGNAL(waiting()),this,SLOT(setUnitWainting()));
            menu->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
            menu->show();
        }
        else if(cursorState==2)
        {
            cursor->getPlayer()->getUnit(unitPosX,unitPosY)->attack(cursor->getOpponent()->getUnit(cursor->getPosX(),cursor->getPosY()));
            centerZone.attackReset();
            cursorState=0;
        }
    }
    if (event->key() == Qt::Key_Escape || event->key() == Qt::Key_Backspace){
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
            QObject::connect(menu,SIGNAL(nextPlayer()),this,SLOT(switchPlayer()));
            menu->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
            menu->show();
        }
    }
}

GameWindow* MainWindow::getWidget()
{
    return &centerZone;
}

void MainWindow::updateWidget()
{
    centerZone.updateMap();
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
}

void MainWindow::switchPlayer()
{
    cursor->switchPlayerState();
}

void MainWindow::setUnitWainting()
{
    cursor->getPlayer()->getUnit(static_cast<unsigned int>(cursor->getPosX()),static_cast<unsigned int>(cursor->getPosY()))->wait();
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
}

void MainWindow::unitCapture()
{
    cursor->getPlayer()->getUnit(static_cast<unsigned int>(cursor->getPosX()),static_cast<unsigned int>(cursor->getPosY()))->capture();
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
