#ifndef TANK_H
#define TANK_H
#include "unit.h"

class Tank :public Unit
{
public:
    Tank(int pos[2],int color, int round,vector<vector<int>> *TDC,Map *PTM);
};

#endif // TANK_H
