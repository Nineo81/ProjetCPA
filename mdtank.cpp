#include "mdtank.h"

mdtank::mdtank(int pos[2],int color, int round,vector<vector<int>> *DC):Unit(pos, color, round,DC)
{
    this->type=6;
    this->absMP=5;
    this->MP=this->absMP;
    this->cost=16000;
    this->move_type="T";

}
