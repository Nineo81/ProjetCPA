#include "infantery.h"

infantery::infantery(int pos[2],int color, int round):Unit(pos, color, round)
{
    this->type=5;
    this->absMP=3;
    this->MP=this->absMP;
    this->cost=1000;
    this->move_type="F";

}
