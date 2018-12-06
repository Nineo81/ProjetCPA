#include "bomber.h"

Bomber::Bomber(vector<unsigned int> pos,int color, int round,Game *game):AirUnit(pos, color, round,game)
{
    this->type=57;

}
