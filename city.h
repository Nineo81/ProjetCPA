#ifndef CITY_H
#define CITY_H
#include "building.h"
#include "player.h"

class City:public Building
{
public:
    City(int pos[2], Player* player);
    City(int pos[2]);
    void setLife(int damage, Player* attacker);
private:
};

#endif // CITY_H
