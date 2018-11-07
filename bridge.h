#ifndef BRIDGE_H
#define BRIDGE_H
#include "terrain.h"

class Bridge: public Terrain
{
public:
    Bridge(int pos[2]);
};

#endif // BRIDGE_H
