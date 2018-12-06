#ifndef MEGATANK_H
#define MEGATANK_H
#include "unit.h"


class megatank : public Unit
{
public:
    megatank(vector<unsigned int> pos,int color, int round,Game *game);
};

#endif // MEGATANK_H
