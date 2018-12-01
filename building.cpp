#include "building.h"

Building::Building(int pos[2], Player* player):GameObject (pos)
{
    life = 20;
    this->player = player;
}

Building::Building(int pos[2]):GameObject(pos){
    life = 20;
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
