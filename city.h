#ifndef CITY_H
#define CITY_H
#include "building.h"

class City:public Building
{
public:
    City(int pos[2], int app);
};

#endif // CITY_H
