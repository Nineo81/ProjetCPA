#ifndef AIRPORT_H
#define AIRPORT_H
#include "building.h"
#include "airunit.h"
#include "player.h"
#include "map.h"

class Airport:public Building
{
public:

    Airport(int pos[2], Player* player,vector<vector<int>> *DC,Map *PTM,Map *PUM);
    Airport(int pos[2],vector<vector<int>> *DC,Map *PTM,Map *PUM);


    void createUnit(int typeUnit);

    void setLife(int damage, Player* attacker);
    virtual ~Airport();
private:
    vector<vector<int>> *DC;
    Map *PTM;
    Map *PUM;
};

#endif // AIRPORT_H
