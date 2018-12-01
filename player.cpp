#include "player.h"

Player::Player(int playerNumber, vector<Building*> firstBuildings,Map* terrainMap,Map* unitMap)
{
    this->playerNumber = playerNumber;
    this->terrainMap=terrainMap;
    this->unitMap=unitMap;
    this->listBuilding=firstBuildings;
    this->money=1000*(this->listBuilding.size());
    for (Building* b : listBuilding) {
        b->setPlayer(this);
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
    if (playerNumber == 1){
        terrainMap->setElement(building->getType()+4,building->get_X(),building->get_Y());
    }
    else if (playerNumber == 2){
        terrainMap->setElement(building->getType()+9,building->get_X(),building->get_Y());
    }
}

Building* Player::getBuilding(int X, int Y)
{
    Building* build = nullptr;
    for (Building* b:listBuilding){
        if (b->get_X() == X && b->get_Y() == Y){
            build = b;
        }
    }
    return build;
}

void Player::delete_building(Building* building){
    unsigned int i = 0;
    while (listBuilding[i] != building){
        i++;
    }
    if ( i < listBuilding.size()){
       listBuilding.erase(listBuilding.begin()+static_cast<int>(i));
    }
    else {cout<<"Bâtiment non trouvé"<<endl;}

}

void Player::delete_unit(Unit *unit){
    unsigned int i = 0;
    while (listUnit[i] != unit){
        i++;
    }
    if ( i < listUnit.size()){
       listUnit.erase(listUnit.begin()+static_cast<int>(i));
    }
    else {cout<<"Unité non trouvée"<<endl;}

}

void Player::add_unit(Unit* unit)
{
    listUnit.push_back(unit);
}

vector<Building*> Player::get_listBuilding(){
    return listBuilding;
}

vector<Unit*> Player::get_listUnit(){
    return listUnit;
}

bool Player::hasUnit(int X, int Y){
    bool b = false;
    for (Unit* u : listUnit){
        if (u->get_X() == X && u->get_Y() == Y){
            b = true;
        }
    }
    return b;
}

int Player::hasBuilding(int X,int Y)
{
    int type = 0;
    for (Building* b:listBuilding){
        if (b->get_X() == X && b->get_Y() == Y){
            type=b->getType();
        }
    }
    return type;
}

bool Player::lost(){
    bool b = false;
    if (listBuilding.size() == 0 && listUnit.size() == 0){
        b = true;
    }
    return b;
}

int Player::getPlayerNumber(){
    return playerNumber;
}
