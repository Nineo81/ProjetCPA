#include "building.h"

Building::Building(int pos[2], Player* player)
{
    life = 20;
    this->player = player;
    position[0]=pos[0];
    position[1]=pos[1];
}

Building::Building(int pos[2]){
    life = 20;
    position[0]=pos[0];
    position[1]=pos[1];
}

int Building::get_X()
{
    return position[0];
}

int Building::get_Y()
{
    return position[1];
}

int Building::getLife() const{
    return life;
}


void Building::setPlayer(Player* player){
    this->player = player;
}

int Building::getType() const{
    return type;
}

void Building::setposition(int newposition[2]){
    std::cout<<"La position d'un bâtiment ne peut être changée";
}

void Building::setLife(int damage, Player* attacker){}

void Building::createUnit(int typeUnit){}

Building::~Building(){}
