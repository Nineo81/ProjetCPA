#ifndef AIRPORT_H
#define AIRPORT_H
#include "building.h"
#include "airunit.h"
#include "player.h"
#include "map.h"
#include "game.h"
#include <vector>
using namespace std;

class Airport:public Building
{
public:

    Airport(vector<unsigned int> pos, Player* player,Game *game);
    Airport(vector<unsigned int> pos,Game *game);


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
