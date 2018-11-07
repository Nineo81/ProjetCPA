#ifndef FACTORY_H
#define FACTORY_H
#include "building.h"
#include "player.h"
#include "unit.h"

class Factory:public Building
{
public:
    Factory(int pos[2], int color, Player* player);
    Unit* createUnit(int typeUnit);   //changer le nom du type selon

private:
    int typeUnit;
    Player* player;
};

#endif // FACTORY_H
