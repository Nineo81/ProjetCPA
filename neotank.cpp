#include "neotank.h"

neotank::neotank(int pos[2],int color, int round,vector<vector<int>> *TDC,Map *PTM):Unit(pos, color, round,TDC,PTM)
{
    this->type=53;
    this->absMP=6;
    this->MP=this->absMP;
    this->cost=22000;
    this->move_type=2;

}
