#ifndef AIRUNIT_H
#define AIRUNIT_H
#include "unit.h"

class AirUnit : public Unit
{
public:
    AirUnit(int pos[2],int color, int round,vector<vector<int>> *DC);
};

#endif // AIRUNIT_H
