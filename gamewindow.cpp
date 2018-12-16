#include "gamewindow.h"
#include <iostream>
#include <QPainter>
#include <vector>
#include <string>
#include <QImage>
#include <QApplication>
#include <QPoint>
#include <QScreen>
#include <string>
#include <unistd.h>
#include "unit.h"
using namespace std;

GameWindow::GameWindow(Map *terrainMap,Map *unitMap,Cursor* cursor) :terrainMap(terrainMap),unitMap(unitMap),cursor(cursor)
{
    money=0;
    player=0;
    button1 = new QPushButton("Pass Turn",this);
    QObject::connect(button1,SIGNAL(clicked()),this,SLOT(sendNextTurn()));
    button2 = new QPushButton("End Game",this);
    QObject::connect(button2,SIGNAL(clicked()),this,SLOT(endingGame()));
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
    QFont font("Times",sizePicture/3,QFont::Bold);
    sizePicture = static_cast<int>(height/(terrainMap->getSize('y')+1));
    painter.setFont(font);
    painter.drawText(QPoint(sizePicture*(terrainMap->getSize('x')+2),sizePicture*3),("Player's money : " + to_string(money)).c_str());
    painter.drawText(QPoint(sizePicture*(terrainMap->getSize('x')+2),sizePicture*2),("Turn of player " + to_string(player)).c_str());
    button1->setGeometry(sizePicture*(terrainMap->getSize('x')+2),sizePicture*4,sizePicture*3,sizePicture);
    button1->setFont(font);
    button2->setGeometry(sizePicture*(terrainMap->getSize('x')+5),sizePicture*4,sizePicture*3,sizePicture);
    button2->setFont(font);

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
    if(cursor->getPlayer())
    {
        for(Unit* u :cursor->getPlayer()->get_listUnit())
        {
            painter.drawText(QPoint((u->get_X()+1)*sizePicture,(u->get_Y()+1)*sizePicture),to_string(u->getHP()).c_str());
        }
        for(Unit* u :cursor->getOpponent()->get_listUnit())
        {
            painter.drawText(QPoint((u->get_X()+1)*sizePicture,(u->get_Y()+1)*sizePicture),to_string(u->getHP()).c_str());
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
    painter.drawImage(QRect(sizePicture*(cursor->getPosX()+1),sizePicture*(cursor->getPosY()+1),sizePicture,sizePicture),QImage("cursor.png"));
    cursor->setSizePicture(sizePicture);
}

void GameWindow::updateMap(int money, int player)
{
    setMoney(money);
    setPlayer(player);
    update();
}

void GameWindow::setSize(double width,double height)
{
    this->width=static_cast<unsigned int>(width);
    this->height=static_cast<unsigned int>(height);
    resize(static_cast<int>(this->width),static_cast<int>(this->height));
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

void GameWindow::setMoney(int money)
{
    this->money=money;
}

void GameWindow::setPlayer(int player)
{
    this->player=player;
}

void GameWindow::sendNextTurn()
{
    emit nextTurn();
}

void GameWindow::endingGame()
{
    emit endOfGame();
}
