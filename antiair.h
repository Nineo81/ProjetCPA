#ifndef ANTIAIR_H
#define ANTIAIR_H
#include "unit.h"

class AntiAir : public Unit
{
public:
    AntiAir(vector<unsigned int> pos,int color, int round, Game *game);
};

#endif // ANTIAIR_H
