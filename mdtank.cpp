#include "mdtank.h"

mdtank::mdtank(int pos[2],int color, int round,vector<vector<int>> *TDC,Map *PTM,Map *PUM):Unit(pos, color, round,TDC,PTM,PUM)
{
    this->type=51;
    this->absMP=5;
    this->MP=this->absMP;
    this->cost=16000;
    this->move_type=2;

}
