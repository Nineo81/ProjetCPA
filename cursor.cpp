#include "cursor.h"

Cursor::Cursor(unsigned int posX,unsigned int posY,Map* unitMap,Map* terrainMap):posX(posX),posY(posY),unitMap(unitMap),terrainMap(terrainMap),playerOS(nullptr),playerBM(nullptr)
{
    playerState = 2; // Le jeu commence par le tour du joueur 2 (BM)
}

void Cursor::move(int up,int left,int down,int right)
{
    if(posX - left >= 0){this->posX = posX - left;}
    if(posX + right <= static_cast<int>(terrainMap->getSize('x')) -1 ){this->posX = posX + right;}
    if(posY-up >= 0){this->posY = posY - up;}
    if(posY+down <= static_cast<int>(terrainMap->getSize('y')) - 1 ){this->posY=posY+down;}
}

void Cursor::moveAlt(int up,int left,int down,int right) //Vérifie que le cursor sera bien dans la zone autorisée pour l'unité
{
    for(std::vector<int> pos : movements)
    {
        if(pos[0] == posX - left + right && pos[1] == posY - up + down)
        {
            this->posX = pos[0];
            this->posY = pos[1];
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
    return sizePicture*(posX + 1);
}

void Cursor::setPosition(int realX, int realY){
    posX = realX/sizePicture -1;
    posY = realY/sizePicture -1;

}

int Cursor::getRealY()
{
    return sizePicture*(posY+1);
}
Player* Cursor::getPlayer()
{
    Player* player = nullptr;
    if(playerState == 1)
    {
        player = playerOS;
    }
    else
    {
        player = playerBM;
    }
    return player;
}

Player* Cursor::getOpponent()
{
    Player* opponent = nullptr;
    if(playerState == 2)
    {
        opponent = playerOS;
    }
    else
    {
        opponent = playerBM;
    }
    return opponent;
}

void Cursor::switchPlayerState()
{
    //procède à l'échange de joueur, modifie l'argent du jour avant le début de leur tour
    if(playerState == 1)
    {
        playerState = 2;
        playerBM->setTurn(true);
        for (Unit *unit:playerBM->get_listUnit())
        {
            unit->setCanPlay(true);
            int posX = unit->get_X(); int posY=unit->get_Y();
            if(terrainMap->getElement(posX,posY) == 43 || terrainMap->getElement(posX,posY) == 44)
            {

                if(((playerBM->get_money()) - ((unit->getcost()) / 10)) >0 && unit->getHP() < 10)
                {
                    unit->setHP(2,'a');
                    playerBM->set_money((unit->getcost()) / 10,'d');

                }


            }
        }
        playerBM->set_money( 1000 * static_cast<int>(playerBM->get_listBuilding().size()),'a');

    }
    else
    {
        playerState = 1;
        playerOS->setTurn(true);
        for (Unit *unit:playerOS->get_listUnit())
        {
            unit->setCanPlay(true);
            int posX=unit->get_X(); int posY=unit->get_Y();
            if(terrainMap->getElement(posX,posY) == 38 || terrainMap->getElement(posX,posY) == 39)
            {
                if(((playerOS->get_money())-((unit->getcost()) / 10)) >0 && unit->getHP() < 10)
                {
                    unit->setCanPlay(true);
                    unit->setHP(2,'a');
                    playerOS->set_money((unit->getcost()) / 10,'d');
                }

            }
        }
        playerOS->set_money(1000 * static_cast<int>(playerOS->get_listBuilding().size()),'a');

    }
}

void Cursor::setPlayer(Player* player,int type)
{
    if(type == 1)
    {
        playerOS=player;
    }
    if(type == 2)
    {
        playerBM=player;
    }
}

bool Cursor::unitOfPlayer()
{
    if(playerState == 1) {
        return playerOS->hasUnit(posX, posY);
    } else {
        return playerBM->hasUnit(posX, posY);
    }

}

vector<vector<int>> Cursor::opponnentUnit() //renvoie une listes des unités pouvant être attaquées
{
    vector<vector<int>> opponnent;
    vector<vector<int>> position={{static_cast<int>(posX-1),static_cast<int>(posY)},{static_cast<int>(posX+1),static_cast<int>(posY)},{static_cast<int>(posX),static_cast<int>(posY-1)},{static_cast<int>(posX),static_cast<int>(posY+1)}};
    for(vector<int> pos : position)
    {
        if (pos[0] > 0 && pos[1] > 0 && pos[0] < unitMap->getSize('x') && pos[1] < unitMap->getSize('y'))
        {
            if(unitMap->getElement(pos[0],pos[1])!= 0 && !getPlayer()->hasUnit(pos[0],pos[1]))
            {
                opponnent.push_back(pos);
            }
        }
    }
    return opponnent;
}

int Cursor::buildOfPlayer()
{
    int state = 0;
    if(playerState == 1)
    {
        state = playerOS->hasBuilding(posX,posY);
    }
    else
    {
        state = playerBM->hasBuilding(posX,posY);
    }
    return state;
}

bool Cursor::onABuilding()
{
    bool rep = false;
    int element = terrainMap->getElement(posX,posY);
    if(element <= 47 && element >= 34)
    {

        if(playerState == 1 && element != 38 && element != 39 && element != 40 && element != 42 && (unitMap->getElement(posX,posY) == 50 || unitMap->getElement(posX,posY) == 58))
        {
            rep=true;
        }
        else if(playerState == 2 && element != 43 && element != 44 && element != 45 && element != 47 && (unitMap->getElement(posX,posY) == 61 || unitMap->getElement(posX,posY) == 69))

        {
            rep=true;
        }
    }
    return rep;
}

void Cursor::setSizePicture(int sizePicture)
{
    this->sizePicture = sizePicture;
}


void Cursor::updateMovements(vector<vector<int>> movements)
{
    this->movements.clear();
    this->movements = movements;
}

int Cursor::getPlayerState()
{
    return playerState;
}

Map *Cursor::getUnitMap() const
{
    return unitMap;
}

Map* Cursor::getTerrainMap() const
{
    return terrainMap;
}

bool Cursor::canMoveUnit(int posX, int posY)
{
    vector<vector<int>> movements = this->movements;
    bool canMoveUnit = false;
    unsigned i = 0;
    while(i<movements.size() && canMoveUnit == false)
    {
        if (this->getPosX() == movements[i][0] && this->getPosY() == movements[i][1])
            canMoveUnit = true;
        i++;
    }
    return canMoveUnit;
}
