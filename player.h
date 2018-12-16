#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "building.h"
#include "unit.h"
#include "map.h"


class Player
{
public:
    Player(int playerNUmber, vector<Building*> firstBuildings,Map* terrainMap,Map* unitMap);
    vector<Building*> get_listBuilding();
    vector<Unit*> get_listUnit();
    void add_unit(Unit *unit);
    void delete_unit(Unit *unit);
    void add_building(Building* building);
    Building* getBuilding(unsigned int X,unsigned int Y);
    void delete_building(Building* building);
    int get_money();
    void set_money(int diff,char sign);
    bool hasUnit(unsigned int X,unsigned int Y);
    int hasBuilding(unsigned int X,unsigned int Y);
    bool lost();
    int getPlayerNumber();
    bool getTurn();
    void setTurn(bool turn);
    Unit* getUnit(unsigned int x,unsigned int y);
private:
    bool turn;
    int money = 0;
    vector<Unit*> listUnit;
    vector<Building*> listBuilding;
    Map* terrainMap;
    Map* unitMap;
    int playerNumber;
};

#endif // PLAYER_H
