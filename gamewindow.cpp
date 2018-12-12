#include "gamewindow.h"
#include <iostream>
#include <QPainter>
#include <vector>
#include <string>
#include <QImage>
#include <QApplication>
#include <QScreen>
#include <string>
#include <unistd.h>
using namespace std;

GameWindow::GameWindow(Map *terrainMap,Map *unitMap,Cursor* cursor) :terrainMap(terrainMap),unitMap(unitMap),cursor(cursor)
{
    for(int i=1;i<117;i++) //Construction de la liste d'image
    {
        const char* imageName = (std::to_string(i)+".png").c_str();
        if(access(imageName,F_OK)!=-1) //check si l'image existe
        {
            listImage.push_back(QImage(imageName));
        }
        else
        {
            listImage.push_back(QImage());
        }
    }
    movements.push_back(vector<int>(2,-1));
}

void GameWindow::GameWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    sizePicture = static_cast<int>(height/(terrainMap->getSize('y')+1));

    for(unsigned int y=0;y<=terrainMap->getSize('y')-1;y++)
    {
        for(unsigned int x=0;x<=terrainMap->getSize('x')-1;x++)
        {
            painter.drawImage(QRect(sizePicture*(static_cast<int>(x)+1),sizePicture*(static_cast<int>(y)+1),sizePicture,sizePicture),listImage[static_cast<unsigned int>(terrainMap->getElement(x,y)-1)]);
        }

    }
    for(unsigned int y=0;y<=terrainMap->getSize('y')-1;y++)
    {
        for(unsigned int x=0;x<=terrainMap->getSize('x')-1;x++)
        {
            if(unitMap->getElement(x,y) != 0)
            {
                painter.drawImage(QRect(sizePicture*(static_cast<int>(x)+1),sizePicture*(static_cast<int>(y)+1),sizePicture,sizePicture),listImage[static_cast<unsigned int>(unitMap->getElement(x,y)-1)]);
            }
        }

    }
    for(std::vector<int> pos : movements)
    {
        if(pos[0]>=0&&pos[1]>=0)
        {
            painter.fillRect(QRect(sizePicture*(pos[0]+1),sizePicture*(pos[1]+1),sizePicture,sizePicture), QBrush(QColor(128, 128, 255, 128)));
        }
    }
    for(std::vector<int> pos : attack)
    {
        if(pos[0]>=0&&pos[1]>=0)
        {
            painter.fillRect(QRect(sizePicture*(pos[0]+1),sizePicture*(pos[1]+1),sizePicture,sizePicture), QBrush(QColor(128, 128, 255, 128)));
        }
    }
    painter.setPen(Qt::red);
    painter.drawRect(sizePicture*(cursor->getPosX()+1),sizePicture*(cursor->getPosY()+1),sizePicture,sizePicture);
    cursor->setSizePicture(sizePicture);
}

void GameWindow::updateMap()
{
    update();
}

void GameWindow::setSize(double width,double height)
{
    this->width=static_cast<unsigned int>(width);
    this->height=static_cast<unsigned int>(height);
    setFixedSize(static_cast<int>(this->width),static_cast<int>(this->height));
}

void GameWindow::setMovements(vector<vector<int>> movements)
{
    this->movements=movements;
    update();
}

void GameWindow::movementsReset()
{
    movements.clear();
    movements.push_back(vector<int>(2,-1));
    update();
}

void GameWindow::setAttack(vector<vector<int>> attack)
{
    this->attack=attack;
    update();
}

void GameWindow::attackReset()
{
    attack.clear();
    attack.push_back(vector<int>(2,-1));
    update();
}

int GameWindow::getSizePicture()
{
    return sizePicture;
}
