#include "cursor.h"

Cursor::Cursor(int posX,int posY,Map* unitMap,Map* terrainMap):posX(posX),posY(posY),unitMap(unitMap),terrainMap(terrainMap)
{

}

void Cursor::move(int up,int left,int down,int right)
{
    if(posX-left>0){this->posX=posX-left;}
    if(posX+right<static_cast<int>(terrainMap->getSize('p'))){this->posX=posX+right;}
    if(posY-up>0){this->posY=posY-up;}
    if(posY+down<static_cast<int>(terrainMap->getSize('m'))){this->posY=posY+down;}
}

int Cursor::getPosX()
{
    return posX;
}

int Cursor::getPosY()
{
    return posY;
}
