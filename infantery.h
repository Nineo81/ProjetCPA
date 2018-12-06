#ifndef INFANTERY_H
#define INFANTERY_H
#include "unit.h"

class infantery : public Unit
{
public:
    infantery(vector<unsigned int> pos,int color, int round,Game *game);
};

#endif // INFANTERY_H
