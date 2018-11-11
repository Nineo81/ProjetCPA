#include "player.h"

Player::Player(vector<Building*> firstBuildings,Map* terrainMap,Map* unitMap)
{
    this->terrainMap=terrainMap;
    this->unitMap=unitMap;
    this->listBuilding=firstBuildings;
    this->money=1000*(this->listBuilding.size());
    for (int i = 0;i<listBuilding.size();i++){
        listBuilding[i]->setPlayer(this);
    }
}

int Player::get_money(){
    return this->money;
}

void Player::set_money(int diff, char sign){
    if (sign =='d'){
        this->money -= diff;}
    else if (sign == 'a') {
        this->money += diff;
    }
}

void Player::add_building(Building* building){
    listBuilding.push_back(building);
    switch(building->getType())
    {
    case(36):
        terrainMap->setElement(40,building->getPositionX(),building->getPositionY());
        break;
    case(35):
        terrainMap->setElement(39,building->getPositionX(),building->getPositionY());
        break;
    case(34):
        terrainMap->setElement(38,building->getPositionX(),building->getPositionY());
    }
}

void Player::add_unit(Unit unit)
{
    listUnit.push_back(unit);
}
