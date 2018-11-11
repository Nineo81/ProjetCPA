#include "b_copter.h"

B_Copter::B_Copter(int pos[2],int color, int round,vector<vector<int>> *DC):AirUnit(pos, color, round,DC)
{
    this->type=1;

}
