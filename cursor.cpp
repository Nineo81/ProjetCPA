#include "cursor.h"

Cursor::Cursor(int posX,int posY,Map* unitMap,Map* terrainMap):posX(posX),posY(posY),unitMap(unitMap),terrainMap(terrainMap),playerOS(nullptr),playerBM(nullptr)
{
    playerState=1;
}

void Cursor::move(int up,int left,int down,int right)
{
    if(posX-left>0){this->posX=posX-left;}
    if(posX+right<static_cast<int>(terrainMap->getSize('p'))+1){this->posX=posX+right;}
    if(posY-up>0){this->posY=posY-up;}
    if(posY+down<static_cast<int>(terrainMap->getSize('m'))+1){this->posY=posY+down;}
}

int Cursor::getPosX()
{
    return posX;
}

int Cursor::getPosY()
{
    return posY;
}

int Cursor::getRealX()
{
    return sizePicture*posX;
}

int Cursor::getRealY()
{
    return sizePicture*posY;
}

void Cursor::switchPlayerState()
{
    if(playerState==1)
    {
        playerState=2;
    }
    else
    {
        playerState=1;
    }
}

void Cursor::setPlayer(Player* player,int type)
{
    if(type==1)
    {
        playerOS=player;
    }
    if(type==2)
    {
        playerBM=player;
    }
}

bool Cursor::unitOfPlayer()
{
    bool state = false;
    if(unitMap->getElement(static_cast<unsigned int>(posX),static_cast<unsigned int>(posY))!=0)
    {
        if(playerState == 1)
        {
            state=playerOS->hasUnit(posX,posY);
        }
    }
    return state;
}

void Cursor::setSizePicture(int sizePicture)
{
    this->sizePicture=sizePicture;
}
