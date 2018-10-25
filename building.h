#ifndef BUILDING_H
#define BUILDING_H
#include "terrain.h"

class Building:public Terrain
{
protected:
    int life;
public:
    Building(int pos[2], int app);
    int getLife() const;
    void changeLife(int damage);        //on peut changer pour ne pas avoir d'argument
};

#endif // BUILDING_H
