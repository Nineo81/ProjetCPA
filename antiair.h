#ifndef ANTIAIR_H
#define ANTIAIR_H
#include "unit.h"

class AntiAir : public Unit
{
public:
    AntiAir(int pos[2],int color, int round,vector<vector<int>> *TDC,Map *PTM,Map *PUM);
};

#endif // ANTIAIR_H
