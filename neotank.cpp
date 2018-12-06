#include "neotank.h"

neotank::neotank(int pos[2],int color, int round,Game *game):Unit(pos, color, round,game)
{
    this->type=53;
    this->absMP=6;
    this->MP=this->absMP;
    this->cost=22000;
    this->move_type=2;

}
