#include "cursor.h"

Cursor::Cursor(int posX,int posY,Map* unitMap,Map* terrainMap):posX(posX),posY(posY),unitMap(unitMap),terrainMap(terrainMap),playerOS(nullptr),playerBM(nullptr)
{
    playerState=1;
}

void Cursor::move(int up,int left,int down,int right)
{
    if(posX-left>=0){this->posX=posX-left;}
    if(posX+right<=static_cast<int>(terrainMap->getSize('x'))-1){this->posX=posX+right;}
    if(posY-up>=0){this->posY=posY-up;}
    if(posY+down<=static_cast<int>(terrainMap->getSize('y'))-1){this->posY=posY+down;}
}

void Cursor::moveAlt(int up,int left,int down,int right)
{
    for(std::vector<int> pos : movements)
    {
        if(pos[0]==posX-left+right && pos[1]==posY-up+down)
        {
            this->posX=pos[0];
            this->posY=pos[1];
            break;
        }
    }
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
    return sizePicture*(posX+1);
}

int Cursor::getRealY()
{
    return sizePicture*(posY+1);
}
Player* Cursor::getPlayer()
{
    Player* player= nullptr;
    if(playerState==1)
    {
        player=playerOS;
    }
    else
    {
        player=playerBM;
    }
    return player;
}

void Cursor::switchPlayerState()
{
    if(playerState==1)
    {
        playerState=2;
        playerBM->setTurn(true);
        for (Unit *unit:playerBM->get_listUnit())
        {
            unit->setCanPlay(true);
            unit->setHP(2,'a');
        }
        playerBM->set_money(1000*static_cast<int>(playerBM->get_listBuilding().size()),'a');
    }
    else
    {
        playerState=1;
        playerOS->setTurn(true);
        for (Unit *unit:playerOS->get_listUnit())
        {
            unit->setCanPlay(true);
            unit->setHP(2,'a');
        }
        playerOS->set_money(1000*static_cast<int>(playerOS->get_listBuilding().size()),'a');
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
    if(playerState == 1)
    {
        state=playerOS->hasUnit(posX,posY);
    }
    else
    {
        state=playerBM->hasUnit(posX,posY);
    }
    return state;
}

bool Cursor::opponnentUnit()
{
    bool rep=false;
    std::vector<vector<int>> position={{posX-1,posY},{posX+1,posY},{posX,posY-1},{posX,posY+1}};
    for(std::vector<int> pos : position)
    {
        if(unitMap->getElement(pos[0],pos[1])!=0 && unitOfPlayer()==false)
        {
            rep=true;
        }
    }
    return rep;
}

int Cursor::buildOfPlayer()
{
    int state = 0;
    if(playerState == 1)
    {
        state=playerOS->hasBuilding(posX,posY);
    }
    else
    {
        state=playerBM->hasBuilding(posX,posY);
    }
    return state;
}

bool Cursor::onABuilding()
{
    bool rep=false;
    int element = terrainMap->getElement(posX,posY);
    if(element<=45 && element>=34)
    {
        if(playerState==1 && element != 38 && element != 39 && element != 40)
        {
            rep=true;
        }
        else if(playerState==2 && element != 43 && element != 44 && element != 45)
        {
            rep=true;
        }
    }
    return rep;
}

void Cursor::setSizePicture(int sizePicture)
{
    this->sizePicture=sizePicture;
}


void Cursor::updateMovements(vector<vector<int>> movements)
{
    this->movements.clear();
    this->movements=movements;
}

int Cursor::getPlayerState() const
{
    return playerState;
}
