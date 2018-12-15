#ifndef CITY_H
#define CITY_H
#include "building.h"
#include "player.h"
#include "game.h"

class City:public Building
{
public:
    City(vector<unsigned int> pos, Player* player, Game *game);
    City(vector<unsigned int> pos, Game *game,bool isHQ);
    void setLife(int damage, Player* attacker);
    void createUnit(int typeUnit);
    bool getIsHQ() const;

private:
    Game* game;
    bool isHQ;
};

#endif // CITY_H
