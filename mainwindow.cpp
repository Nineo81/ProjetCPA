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

MainWindow::MainWindow(Map *terrainMap,Map *unitMap,Cursor* cursor) : cursor(cursor),centerZone(terrainMap,unitMap,cursor)
{
    setCentralWidget(&centerZone);
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    centerZone.setSize(screenGeometry.width()*0.9,screenGeometry.height()*0.9);
    this->adjustSize();
    move(screen->availableGeometry().center()-this->rect().center());
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
        else if(cursor->buildOfPlayer() == 35)
        {
            BuildingMenu *menu = new BuildingMenu(cursor->getRealX(),cursor->getRealY(),cursor->getPlayer()->getBuilding(cursor->getPosX(),cursor->getPosY()));
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


