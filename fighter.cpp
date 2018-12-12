#include "fighter.h"

Fighter::Fighter(vector<unsigned int> pos,int color, int round,Game *game):AirUnit(pos, color, round,game)
{
    this->type=56;
    this->attack_type=4;
    this->absMP=9;
    this->MP=this->absMP;
    this->cost=20000;
    setUnit();

}
