#include "mainwindow.h"
#include "gamewindow.h"
#include <QPainter>
#include <QKeyEvent>
#include <QMouseEvent>

MainWindow::MainWindow(Map *terrainMap,Map *unitMap,Cursor* cursor) : cursor(cursor),centerZone(terrainMap,unitMap,cursor)
{
    setCentralWidget(&centerZone);
    //centerZone.setFixedSize(600,350);
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


