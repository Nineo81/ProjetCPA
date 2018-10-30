#include "mdtank.h"

mdtank::mdtank(int pos[2],int color, int round):Unit(pos, color, round)
{
    this->absMP=5;
    this->MP=this->absMP;
    this->cost=16000;
    this->move_type="T";

}
