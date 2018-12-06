#ifndef CITY_H
#define CITY_H
#include "building.h"
#include "player.h"
#include "game.h"

class City:public Building
{
public:
    City(int pos[2], Player* player);
    City(int pos[2]);
    void setLife(int damage, Player* attacker);
    void createUnit(int typeUnit);
private:
    Game* Game;
};

#endif // CITY_H
