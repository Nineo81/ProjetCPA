#include "tank.h"

Tank::Tank(int pos[2],int color, int round,Game *game):Unit(pos, color, round,game)
{
    this->type=55;
    this->absMP=6;
    this->MP=this->absMP;
    this->cost=7000;
    this->move_type=2;

}
