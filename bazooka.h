#ifndef BAZOOKA_H
#define BAZOOKA_H
#include "unit.h"

class Bazooka : public Unit
{
public:
    Bazooka(int pos[2],int color, int round,vector<vector<int>> *TDC,Map *PTM);
};

#endif // BAZOOKA_H
