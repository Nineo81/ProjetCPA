#ifndef CITY_H
#define CITY_H
#include "building.h"
#include "player.h"
#include "game.h"

class City:public Building
{
public:
    City(vector<unsigned int> pos, Player* player, Game *game);
    City(vector<unsigned int> pos, Game *game);
    void setLife(int damage, Player* attacker);
    void createUnit(int typeUnit);
private:
    Game* game;
};

#endif // CITY_H
