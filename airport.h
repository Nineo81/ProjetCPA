#ifndef AIRPORT_H
#define AIRPORT_H
#include "building.h"
#include "airunit.h"
#include "player.h"

class Airport:public Building
{
public:
    Airport(int pos[2],int color,Player* player);
    AirUnit* createUnit(int typeUnit);
    void setLife(int damage, Player* attacker);
private:
    Player* player;
};

#endif // AIRPORT_H
