#include "mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    QWidget *centerZone = new QWidget;
    setCentralWidget(centerZone);
    centerZone->setFixedSize(300,150);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.drawRect(50, 100, 20, 40);
}

void MainWindow::setMap(Map *map)
{
    this->map=map;
}
