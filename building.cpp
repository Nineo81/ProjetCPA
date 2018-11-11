#include "building.h"

Building::Building(int pos[2], Player* player):Terrain (pos,3)
{
    life = 20;
    this->player = player;
}

Building::Building(int pos[2]):Terrain (pos,3){
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
