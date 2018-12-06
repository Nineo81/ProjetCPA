#include "fighter.h"

Fighter::Fighter(vector<unsigned int> pos,int color, int round,Game *game):AirUnit(pos, color, round,game)
{
    this->type=56;

}
