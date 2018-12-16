#include "neotank.h"

neotank::neotank(vector<unsigned int> pos,int color, int round,Game *game):Unit(pos, color, round,game)
{
    this->type = 53;
    this->absMP = 6;
    this->MP = this->absMP;
    this->cost = 22000;
    this->move_type = 2;
    this->attack_type = 8;
    setUnit();

}
