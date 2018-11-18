#ifndef CURSOR_H
#define CURSOR_H
#include "map.h"
#include "player.h"


class Cursor
{
public:
    Cursor(int posX,int posY,Map* unitMap,Map* terrainMap);
    void move(int up,int left,int down,int right);
    int getPosX();
    int getPosY();
    void setPlayer(Player* player,int type);
    int getTypeElement(unsigned int posX,unsigned int posY);
private:
    int posX;
    int posY;
    Map* unitMap;
    Map* terrainMap;
    Player* playerOS;
    Player* playerBM;
};

#endif // CURSOR_H
