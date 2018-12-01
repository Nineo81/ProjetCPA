#include "airunit.h"

AirUnit::AirUnit(int pos[2],int color, int round,vector<vector<int>> *TDC,Map *PTM):Unit(pos, color, round,TDC,PTM)
{
    this->move_type=4;

}
