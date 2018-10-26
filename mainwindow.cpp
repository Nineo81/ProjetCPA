#include "mainwindow.h"
#include "gamewindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),centerZone()
{
    setCentralWidget(&centerZone);
    centerZone.setFixedSize(600,350);
}
