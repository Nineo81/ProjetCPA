#ifndef INFANTERY_H
#define INFANTERY_H
#include "unit.h"

class infantery : public Unit
{
public:
    infantery(int pos[2],int color, int round,Game *game);
};

#endif // INFANTERY_H
