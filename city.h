#ifndef CITY_H
#define CITY_H
#include "building.h"
#include "player.h"

class City:public Building
{
public:
    City(int pos[2],int color,Player* player);
    void setLife(int damage, Player* attacker);
private:
    Player* player;
};

#endif // CITY_H
