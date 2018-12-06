#ifndef NEATANK_H
#define NEATANK_H
#include "unit.h"


class neotank : public Unit
{
public:
    neotank(int pos[2],int color, int round,Game *game);
};

#endif // NEATANK_H
