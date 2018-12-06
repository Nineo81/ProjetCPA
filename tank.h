#ifndef TANK_H
#define TANK_H
#include "unit.h"

class Tank :public Unit
{
public:
    Tank(vector<unsigned int> pos,int color, int round,Game *game);
};

#endif // TANK_H
