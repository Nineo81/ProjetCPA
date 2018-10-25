#include "mainwindow.h"
#include "gamewindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    GameWindow *centerZone = new GameWindow;
    setCentralWidget(centerZone);
    centerZone->setFixedSize(600,350);
}
