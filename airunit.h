#ifndef AIRUNIT_H
#define AIRUNIT_H
#include "unit.h"

class AirUnit : public Unit
{
public:
    AirUnit(vector<unsigned int> pos,int color, int round,Game *game);
};

#endif // AIRUNIT_H
