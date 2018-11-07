#include "building.h"

Building::Building(int pos[2], int color):Terrain (pos,3)
{
    life = 20;
}

int Building::getLife() const{
    return life;
}
