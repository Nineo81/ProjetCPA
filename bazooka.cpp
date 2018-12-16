#include "bazooka.h"

Bazooka::Bazooka(vector<unsigned int> pos,int color, int round,Game * game):Unit(pos, color, round,game)
{
    this->type = 58;
    this->move_type = 1;
    this->attack_type = 2;
    this->absMP = 2;
    this->MP = this->absMP;
    this->cost = 3000;
    setUnit();
}
