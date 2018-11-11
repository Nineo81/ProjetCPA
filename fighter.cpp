#include "fighter.h"

Fighter::Fighter(int pos[2],int color, int round,vector<vector<int>> *DC):AirUnit(pos, color, round,DC)
{
    this->type=4;

}
