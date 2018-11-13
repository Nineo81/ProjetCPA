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
    for(int i=1;i<117;i++)
    {
        const char* imageName = (std::to_string(i)+".png").c_str();
        if(access(imageName,F_OK)!=-1) //check si l'image existe
        {
            listImage.push_back(QImage(imageName));
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
            switch(terrainMap->getElement(i,j))
            {
            case(1):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("1.png"));
                break;
            case(2):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("2.png"));
                break;
            case(3):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("3.png"));
                break;
            case(4):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("4.png"));
                break;
            case(5):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("5.png"));
                break;
            case(6):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("6.png"));
                break;
            case(7):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("7.png"));
                break;
            case(8):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("8.png"));
                break;
            case(9):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("9.png"));
                break;
            case(10):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("10.png"));
                break;
            case(11):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("11.png"));
                break;
            case(12):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("12.png"));
                break;
            case(13):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("13.png"));
                break;
            case(14):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("14.png"));
                break;
            case(15):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("15.png"));
                break;
            case(16):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("16.png"));
                break;
            case(17):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("17.png"));
                break;
            case(18):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("18.png"));
                break;
            case(19):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("19.png"));
                break;
            case(20):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("20.png"));
                break;
            case(21):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("21.png"));
                break;
            case(22):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("22.png"));
                break;
            case(23):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("23.png"));
                break;
            case(24):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("24.png"));
                break;
            case(25):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("25.png"));
                break;
            case(26):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("26.png"));
                break;
            case(27):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("27.png"));
                break;
            case(28):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("28.png"));
                break;
            case(29):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("29.png"));
                break;
            case(30):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("30.png"));
                break;
            case(31):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("31.png"));
                break;
            case(32):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("32.png"));
                break;
            case(33):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("33.png"));
                break;
            case(34):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("34.png"));
                break;
            case(35):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("35.png"));
                break;
            case(36):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("36.png"));
                break;
            case(38):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("38.png"));
                break;
            case(39):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("39.png"));
                break;
            case(40):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("40.png"));
                break;
            case(43):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("43.png"));
                break;
            case(44):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("44.png"));
                break;
            case(45):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("45.png"));
                break;
            case(101):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("101.png"));
                break;
            case(102):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("102.png"));
                break;
            case(103):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("103.png"));
                break;
            case(104):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("104.png"));
                break;
            case(105):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("105.png"));
                break;
            case(106):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("106.png"));
                break;
            case(107):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("107.png"));
                break;
            case(108):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("108.png"));
                break;
            case(109):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("109.png"));
                break;
            case(110):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("110.png"));
                break;
            case(113):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("113.png"));
                break;
            case(114):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("114.png"));
                break;
            case(115):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("115.png"));
                break;
            case(116):
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("116.png"));
                break;
            default:
                painter.drawImage(QRect(50*(static_cast<int>(j)+1),50*(static_cast<int>(i)+1),50,50),QImage("1.png"));
            }
        }
    }
}

void GameWindow::updateMap()
{
    update();
}
