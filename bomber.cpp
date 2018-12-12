#include "bomber.h"

Bomber::Bomber(vector<unsigned int> pos,int color, int round,Game *game):AirUnit(pos, color, round,game)
{
    this->type=57;
    this->attack_type=3;
    this->absMP=7;
    this->MP=this->absMP;
    this->cost=22000;
    setUnit();

}
