#include "gamewindow.h"
#include <iostream>
#include <QPainter>
#include <vector>
#include <string>
#include <QImage>
#include <QApplication>
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

    for(unsigned int i=0;i<=terrainMap->getSize('m')-1;i++)
    {
        for(unsigned int j=0;j<=terrainMap->getSize('p')-1;j++)
        {
            painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),listImage[terrainMap->getElement(i,j)-1]);
        }
    }
    painter.setPen(Qt::red);
    painter.drawRect(50*cursor->getPosX(),50*cursor->getPosY(),50,50);
}

void GameWindow::updateMap()
{
    update();
}
