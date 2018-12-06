#ifndef MDTANK_H
#define MDTANK_H
#include"unit.h"


class mdtank : public Unit
{
public:
    mdtank(int pos[2],int color, int round,Game *game);
};

#endif // MDTANK_H
