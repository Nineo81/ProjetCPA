#ifndef BUILDING_H
#define BUILDING_H
#include "terrain.h"

class Building:public Terrain
{
protected:
    int life;
    int color;
public:
    Building(int pos[2], int color);
    int getLife() const;
};

#endif // BUILDING_H
