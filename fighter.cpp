#include "fighter.h"

Fighter::Fighter(int pos[2],int color, int round,vector<vector<int>> *TDC,Map *PTM):AirUnit(pos, color, round,TDC,PTM)
{
    this->type=4;

}
