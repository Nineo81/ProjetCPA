#ifndef ROAD_H
#define ROAD_H
#include "terrain.h"

class Road: public Terrain
{
public:
    Road(int pos[2], int app);
};

#endif // ROAD_H
