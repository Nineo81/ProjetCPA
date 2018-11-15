#ifndef AIRPORT_H
#define AIRPORT_H
#include "building.h"
#include "airunit.h"
#include "player.h"
#include "map.h"

class Airport:public Building
{
public:
    Airport(int pos[2], Player* player,vector<vector<int>> *DC,Map *PTM);
    Airport(int pos[2],vector<vector<int>> *DC,Map *PTM);
    AirUnit* createUnit(int typeUnit);
    void setLife(int damage, Player* attacker);
private:
    vector<vector<int>> *DC;
    Map *PTM;
};

#endif // AIRPORT_H
