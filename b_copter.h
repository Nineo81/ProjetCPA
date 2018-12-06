#ifndef B_COPTER_H
#define B_COPTER_H
#include"airunit.h"

class B_Copter : public AirUnit
{
public:
    B_Copter(vector<unsigned int> pos,int color, int round,Game *game);
};

#endif // B_COPTER_H
