#include "antiair.h"

AntiAir::AntiAir(int pos[2],int color, int round,vector<vector<int>> *DC):Unit(pos, color, round,DC)
{
    this->type=0;
    this->absMP=6;
    this->MP=this->absMP;
    this->cost=8000;
    this->move_type="T";

}
