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
}

void GameWindow::GameWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    int sizePicture = static_cast<int>(height/(terrainMap->getSize('y')+1));

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
    painter.setPen(Qt::red);
    painter.drawRect(sizePicture*cursor->getPosX(),sizePicture*cursor->getPosY(),sizePicture,sizePicture);
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
