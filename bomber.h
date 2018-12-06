#ifndef BOMBER_H
#define BOMBER_H
#include "airunit.h"

class Bomber : public AirUnit
{
public:
    Bomber(int pos[2],int color, int round,Game *game);
};

#endif // BOMBER_H
