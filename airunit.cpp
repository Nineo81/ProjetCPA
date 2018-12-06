#include "airunit.h"

AirUnit::AirUnit(int pos[2],int color, int round,Game *game):Unit(pos, color, round,game)
{
    this->move_type=4;

}
