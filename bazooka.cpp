#include "bazooka.h"

Bazooka::Bazooka(int pos[2],int color, int round,vector<vector<int>> *TDC,Map *PTM):Unit(pos, color, round,TDC,PTM)
{
    this->type=2;
    this->move_type=1;
}
