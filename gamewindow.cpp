#include "gamewindow.h"
#include <QPainter>

GameWindow::GameWindow(QWidget *parent) : QWidget(parent),map(nullptr)
{

}

void GameWindow::GameWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.drawRect(50, 100, 20, 40);
}

void GameWindow::setMap(Map *map)
{
    this->map=map;
}
