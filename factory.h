#ifndef FACTORY_H
#define FACTORY_H
#include "building.h"
#include "player.h"
#include "unit.h"

class Factory:public Building
{
public:
    Factory(int pos[2], Player* player);
    Factory(int pos[2]);
    Unit* createUnit(int typeUnit);   //changer le nom du type selon
    void setLife(int damage, Player* attacker);

private:
};

#endif // FACTORY_H
