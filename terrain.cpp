#include "Terrain.h"

Terrain::Terrain(int pos[2], int def)
{
    position[0] = pos[0];
    position[1] = pos[1];
    defense = def;
}

int Terrain::getDefense() const{
    return defense;
}

int Terrain::getPositionX() const{
    return position[0];
}

int Terrain::getPositionY() const{
    return position[1];
}
