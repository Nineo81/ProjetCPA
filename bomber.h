#ifndef BOMBER_H
#define BOMBER_H
#include "airunit.h"

class Bomber : public AirUnit
{
public:
    Bomber(vector<unsigned int> pos,int color, int round,Game *game);
};

#endif // BOMBER_H
