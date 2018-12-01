#include "bomber.h"

Bomber::Bomber(int pos[2],int color, int round,vector<vector<int>> *TDC,Map *PTM,Map *PUM):AirUnit(pos, color, round,TDC,PTM,PUM)
{
    this->type=57;

}
