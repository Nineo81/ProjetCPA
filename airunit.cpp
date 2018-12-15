#include "airunit.h"

AirUnit::AirUnit(vector<unsigned int> pos,int color, int round,Game *game):Unit(pos, color, round,game)
{
    this->move_type = 4;

}
