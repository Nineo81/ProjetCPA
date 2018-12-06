#ifndef MDTANK_H
#define MDTANK_H
#include"unit.h"


class mdtank : public Unit
{
public:
    mdtank(vector<unsigned int> pos,int color, int round,Game *game);
};

#endif // MDTANK_H
