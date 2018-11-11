#ifndef FIGHTER_H
#define FIGHTER_H
#include "airunit.h"

class Fighter : public AirUnit
{
public:
    Fighter(int pos[2],int color, int round,vector<vector<int>> *DC);
};

#endif // FIGHTER_H
