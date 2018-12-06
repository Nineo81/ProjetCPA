#include "megatank.h"

megatank::megatank(int pos[2],int color, int round,Game *game):Unit(pos, color, round,game)
{
    this->type=52;
    this->absMP=4;
    this->MP=this->absMP;
    this->cost=28000;
    this->move_type=2;

}
