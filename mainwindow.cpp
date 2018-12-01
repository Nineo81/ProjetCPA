#include "mainwindow.h"
#include "gamewindow.h"
#include <QPainter>
#include <QApplication>
#include <QScreen>
#include <QStyle>
#include <QKeyEvent>
#include <QMouseEvent>
#include "unitmenu.h"

MainWindow::MainWindow(Map *terrainMap,Map *unitMap,Cursor* cursor) : cursor(cursor),centerZone(terrainMap,unitMap,cursor)
{
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
    config["firstplayer"] = 10;
    config["youplay"] = "firstPlayer";
    QJsonObject unit1;
    unit1["country"] = 10;
    unit1["type"] = "infantry";
    unit1["x"] = 15;
    unit1["y"] = 3;
    config["units"] = unit1;
    sendJson(config);
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
        cursor->move(0,1,0,0);
        centerZone.updateMap();
    }
    if (event->key() == Qt::Key_Right){
        cursor->move(0,0,0,1);
        centerZone.updateMap();
    }
    if (event->key() == Qt::Key_Up){
    //faire bouger la case ou l'option (dans un menu) selectionee
        cursor->move(1,0,0,0);
        centerZone.updateMap();
    }
    if (event->key() == Qt::Key_Down){
        cursor->move(0,0,1,0);
        centerZone.updateMap();
    }
    if (event->key() == Qt::Key_Space || event->key() == Qt::Key_Enter){
    //confirmer la selection == bouton A
        if(cursor->unitOfPlayer())
        {
            UnitMenu *menu = new UnitMenu(cursor->getRealX(),cursor->getRealY());
            menu->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
            menu->show();
        }
    }
    if (event->key() == Qt::Key_Escape || event->key() == Qt::Key_Backspace){
    //retour == bouton B

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


