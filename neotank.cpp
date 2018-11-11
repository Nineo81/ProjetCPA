#include "neotank.h"

neotank::neotank(int pos[2],int color, int round,vector<vector<int>> *DC):Unit(pos, color, round,DC)
{
    this->type=8;
    this->absMP=6;
    this->MP=this->absMP;
    this->cost=22000;
    this->move_type=2;

}
