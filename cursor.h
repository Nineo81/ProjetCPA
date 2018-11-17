#ifndef CURSOR_H
#define CURSOR_H
#include "map.h"


class Cursor
{
public:
    Cursor(int posX,int posY,Map* unitMap,Map* terrainMap);
    void move(int up,int left,int down,int right);
    int getPosX();
    int getPosY();
private:
    int posX;
    int posY;
    Map* unitMap;
    Map* terrainMap;
};

#endif // CURSOR_H
