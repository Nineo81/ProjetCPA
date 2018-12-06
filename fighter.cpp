#include "fighter.h"

Fighter::Fighter(int pos[2],int color, int round,Game *game):AirUnit(pos, color, round,game)
{
    this->type=56;

}
