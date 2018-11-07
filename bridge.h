#ifndef BRIDGE_H
#define BRIDGE_H
#include "terrain.h"

class Bridge: public Terrain
{
public:
    Bridge(int pos[2], int app);
};

#endif // BRIDGE_H
