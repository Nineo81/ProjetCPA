#ifndef NEATANK_H
#define NEATANK_H
#include "unit.h"


class neotank : public Unit
{
public:
    neotank(int pos[2],int color, int round,vector<vector<int>> *TDC,Map *PTM);
};

#endif // NEATANK_H
