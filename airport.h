#ifndef AIRPORT_H
#define AIRPORT_H
#include "building.h"
#include "airunit.h"
#include "player.h"

class Airport:public Building
{
public:
    Airport(int pos[2], Player* player,vector<vector<int>> *DC);
    Airport(int pos[2],vector<vector<int>> *DC);
    AirUnit* createUnit(int typeUnit);
    void setLife(int damage, Player* attacker);
private:
    vector<vector<int>> *DC;
};

#endif // AIRPORT_H
