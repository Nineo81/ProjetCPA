#ifndef CITY_H
#define CITY_H
#include "building.h"
#include "player.h"
#include "game.h"

class City:public Building
{
public:
    City(vector<unsigned int> pos, Player* player);
    City(vector<unsigned int> pos);
    void setLife(int damage, Player* attacker);
    void createUnit(int typeUnit);
private:
    Game* Game;
};

#endif // CITY_H
