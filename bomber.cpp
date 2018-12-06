#include "bomber.h"

Bomber::Bomber(int pos[2],int color, int round,Game *game):AirUnit(pos, color, round,game)
{
    this->type=57;

}
