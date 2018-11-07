#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "unit.h"
#include"building.h"
#include"city.h"


class Player
{
private:
    int money;
    vector<Unit> listUnit;
    vector<Building> listBuilding;
public:
    Player(vector<Building> firstBuildings);
    vector<Building>* get_listBuilding();
    vector<Unit>* get_listUnit();
    void add_unit(Unit unit);
    void delete_unit(Unit unit);
    void add_building(Building building);
    void delete_building(Building building);
    int get_money();
    int set_money(int diff,char sign);

};

#endif // PLAYER_H
