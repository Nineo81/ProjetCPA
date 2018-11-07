#include "neotank.h"

neotank::neotank(int pos[2],int color, int round):Unit(pos, color, round)
{
    this->type=8;
    this->absMP=6;
    this->MP=this->absMP;
    this->cost=22000;
    this->move_type="T";

}
