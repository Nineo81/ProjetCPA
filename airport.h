#ifndef AIRPORT_H
#define AIRPORT_H
#include "building.h"
#include "airunit.h"
#include "player.h"
#include "map.h"
#include "game.h"

class Airport:public Building
{
public:

    Airport(int pos[2], Player* player,Game *game);
    Airport(int pos[2],Game *game);


    void createUnit(int typeUnit);

    void setLife(int damage, Player* attacker);
    virtual ~Airport();
private:
    Game* game;
    vector<vector<int>> *DC;
    Map *PTM;
    Map *PUM;
};

#endif // AIRPORT_H
