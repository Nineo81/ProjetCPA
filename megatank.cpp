#include "megatank.h"

megatank::megatank(int pos[2],int color, int round,vector<vector<int>> *DC):Unit(pos, color, round,DC)
{
    this->type=7;
    this->absMP=4;
    this->MP=this->absMP;
    this->cost=28000;
    this->move_type=2;

}
