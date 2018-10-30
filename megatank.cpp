#include "megatank.h"

megatank::megatank(int pos[2],int color, int round):Unit(pos, color, round)
{
    this->absMP=4;
    this->MP=this->absMP;
    this->cost=28000;
    this->move_type="T";

}
