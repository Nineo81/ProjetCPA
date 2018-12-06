#include "b_copter.h"

B_Copter::B_Copter(vector<unsigned int> pos,int color, int round,Game *game):AirUnit(pos, color, round,game)
{
    this->type=59;

}
