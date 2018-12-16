#include "b_copter.h"

B_Copter::B_Copter(vector<unsigned int> pos,int color, int round,Game *game):AirUnit(pos, color, round,game)
{
    this->attack_type = 1;
    this->type = 59;
    this->absMP = 6;
    this->MP = this->absMP;
    this->cost = 9000;
    setUnit();

}
