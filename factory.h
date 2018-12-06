#ifndef FACTORY_H
#define FACTORY_H
#include "building.h"
#include "player.h"
#include "unit.h"
#include "map.h"
#include "game.h"

class Factory:public Building
{
public:

    Factory(int pos[2], Player* player,Game *game);
    Factory(int pos[2],Game *game);

    void createUnit(int typeUnit);   //changer le nom du type selon

    void setLife(int damage, Player* attacker);
    virtual ~Factory();
private:
    Game* game;
};

#endif // FACTORY_H
