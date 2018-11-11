#include "recon.h"

Recon::Recon(int pos[2],int color, int round,vector<vector<int>> *DC):Unit(pos, color, round,DC)
{
    this->type=9;
    this->absMP=8;
    this->MP=this->absMP;
    this->cost=4000;
    this->move_type=3;

}
