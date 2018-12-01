#include "infantery.h"

infantery::infantery(int pos[2],int color, int round,vector<vector<int>> *TDC,Map *PTM,Map *PUM):Unit(pos, color, round,TDC,PTM,PUM)
{
    this->type=50;
    this->absMP=3;
    this->MP=this->absMP;
    this->cost=1000;
    this->move_type=0;

}
