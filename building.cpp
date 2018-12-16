#include "building.h"

Building::Building(vector<unsigned int> pos, Player* player)
{
    life = 20;
    this->player = player;
    position.push_back(pos[0]);
    position.push_back(pos[1]);
}

Building::Building(vector<unsigned int> pos){
    life = 20;
    position.push_back(pos[0]);
    position.push_back(pos[1]);
}

unsigned int Building::get_X()
{
    return position[0];
}

unsigned int Building::get_Y()
{
    return position[1];
}

int Building::getLife() const{
    return life;
}

void Building::resetLife(){
    life = 20;
}

void Building::setPlayer(Player* player){
    this->player = player;
}

int Building::getType() const{
    return type;
}

void Building::setLife(int damage, Player* attacker){}

void Building::createUnit(int typeUnit){}

Building::~Building(){}
