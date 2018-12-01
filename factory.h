#ifndef FACTORY_H
#define FACTORY_H
#include "building.h"
#include "player.h"
#include "unit.h"
#include "map.h"

class Factory:public Building
{
public:

    Factory(int pos[2], Player* player,vector<vector<int>> *DC,Map *PTM,Map *PUM);
    Factory(int pos[2],vector<vector<int>> *DC,Map *PTM,Map *PUM);

    void createUnit(int typeUnit);   //changer le nom du type selon

    void setLife(int damage, Player* attacker);
    virtual ~Factory();
private:
    vector<vector<int>> *DC;
    Map *PTM;
    Map *PUM;
};

#endif // FACTORY_H
