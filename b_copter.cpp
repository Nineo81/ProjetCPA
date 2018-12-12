#include "b_copter.h"

B_Copter::B_Copter(vector<unsigned int> pos,int color, int round,Game *game):AirUnit(pos, color, round,game)
{
    this->attack_type=1;
    this->type=59;

}
