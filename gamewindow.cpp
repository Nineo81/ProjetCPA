#include "gamewindow.h"
#include <QPainter>
#include <vector>

GameWindow::GameWindow(QWidget *parent) : QWidget(parent),map(nullptr)
{

}

void GameWindow::GameWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.drawRect(50, 100, 20, 40);
    for(int i=0;i<=map->size();i++)
    {

    }
}

void GameWindow::setMap(Map *map)
{
    this->map=map;
}
