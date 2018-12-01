#ifndef B_COPTER_H
#define B_COPTER_H
#include"airunit.h"


class B_Copter : public AirUnit
{
public:
    B_Copter(int pos[2],int color, int round,vector<vector<int>> *TDC,Map *PTM);
};

#endif // B_COPTER_H
