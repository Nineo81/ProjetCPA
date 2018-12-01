#include "megatank.h"

megatank::megatank(int pos[2],int color, int round,vector<vector<int>> *TDC,Map *PTM,Map *PUM):Unit(pos, color, round,TDC,PTM,PUM)
{
    this->type=52;
    this->absMP=4;
    this->MP=this->absMP;
    this->cost=28000;
    this->move_type=2;

}
