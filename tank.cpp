#include "tank.h"

Tank::Tank(int pos[2],int color, int round):Unit(pos, color, round)
{
    this->type=10;
    this->absMP=6;
    this->MP=this->absMP;
    this->cost=7000;
    this->move_type="T";

}
