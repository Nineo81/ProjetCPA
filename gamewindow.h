#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include "map.h"
#include "cursor.h"
#include <vector>
#include <QLabel>

class GameWindow : public QWidget
{
    Q_OBJECT
public:
    explicit GameWindow(Map *terrainMap=nullptr,Map *unitMap=nullptr,Cursor* cursor=nullptr);

    void paintEvent(QPaintEvent *event);
    void setSize(double width,double height);
    void updateMap(int money, int player);
    void movementsReset();
    void setMovements(vector<vector<int>> movements);
    void attackReset();
    void setAttack(vector<vector<int>> attack);
    int getSizePicture();
    void setMoney(int money);
    void setPlayer(int player);
private:
    int money;
    int player;
    int sizePicture;
    unsigned int height;
    unsigned int width;
    Map *terrainMap;
    Map *unitMap;
    Cursor* cursor;
    vector<QImage> listImage;
    vector<vector<int>> movements;
    vector<vector<int>> attack;
signals:

public slots:
};

#endif // GAMEWINDOW_H
