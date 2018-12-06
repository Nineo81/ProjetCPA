#include "antiair.h"

AntiAir::AntiAir(int pos[2],int color, int round, Game* game):Unit(pos, color, round, game)
{
    this->type=60;
    this->absMP=6;
    this->MP=this->absMP;
    this->cost=8000;
    this->move_type=2;

}
