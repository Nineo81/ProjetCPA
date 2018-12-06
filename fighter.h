#ifndef FIGHTER_H
#define FIGHTER_H
#include "airunit.h"

class Fighter : public AirUnit
{
public:
    Fighter(vector<unsigned int> pos,int color, int round,Game *game);
};

#endif // FIGHTER_H
