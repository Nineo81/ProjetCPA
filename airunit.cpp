#include "airunit.h"

AirUnit::AirUnit(int pos[2],int color, int round,vector<vector<int>> *TDC,Map *PTM,Map *PUM):Unit(pos, color, round,TDC,PTM,PUM)
{
    this->move_type=4;

}
