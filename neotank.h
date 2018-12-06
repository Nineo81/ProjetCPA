#ifndef NEATANK_H
#define NEATANK_H
#include "unit.h"


class neotank : public Unit
{
public:
    neotank(vector<unsigned int> pos,int color, int round,Game *game);
};

#endif // NEATANK_H
