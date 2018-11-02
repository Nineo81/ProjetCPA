#include "antiair.h"

AntiAir::AntiAir(int pos[2],int color, int round):Unit(pos, color, round)
{
    this->type=1;
    this->absMP=6;
    this->MP=this->absMP;
    this->cost=8000;
    this->move_type="T";

}
