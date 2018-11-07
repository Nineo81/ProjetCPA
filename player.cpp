#include "player.h"

Player::Player(vector<Building> firstBuildings)
{
    this->listBuilding=firstBuildings;
    this->money=1000*(this->listBuilding.size());


}
