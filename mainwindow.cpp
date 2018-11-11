#include "mainwindow.h"
#include "gamewindow.h"
#include <QPainter>
#include <QKeyEvent>
#include <QMouseEvent>

MainWindow::MainWindow(Map *terrainMap,Map *unitMap,Cursor* cursor) : centerZone(terrainMap,unitMap,cursor)
{
    setCentralWidget(&centerZone);
    //centerZone.setFixedSize(600,350);
}

void MainWindow::keyPressEvent(QKeyEvent * event){
    /*Je ne suis pas sure que ce sera ici a la fin,
     * ça depend de comment on fait notre truc il me semble.*/
    if (event->key() == Qt::Key_Left){
    //faire bouger la case selectionnee vers la gauche
    }
    if (event->key() == Qt::Key_Right){

    }
    if (event->key() == Qt::Key_Up){
    //faire bouger la case ou l'option (dans un menu) selectionee
    }
    if (event->key() == Qt::Key_Down){

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


