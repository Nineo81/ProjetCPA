#ifndef RIVER_H
#define RIVER_H
#include "terrain.h"

class River: public Terrain
{
public:
    River(int pos[2], int app);
};

#endif // RIVER_H
