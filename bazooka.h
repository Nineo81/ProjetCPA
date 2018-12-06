#ifndef BAZOOKA_H
#define BAZOOKA_H
#include "unit.h"

class Bazooka : public Unit
{
public:
    Bazooka(vector<unsigned int> pos,int color, int round,Game *game);
};

#endif // BAZOOKA_H
