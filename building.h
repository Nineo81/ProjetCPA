#ifndef BUILDING_H
#define BUILDING_H
#include "gameobject.h"
#include "unit.h"

class Player;
class Building
{
protected:
    int life;
    int color;
    Player* player;
    int type;
    vector<unsigned int> position;
public:
    Building(vector<unsigned int> pos, Player* player);
    Building(vector<unsigned int> pos);
    int getLife() const;
    void setPlayer(Player* player);
    int getType() const;
    unsigned int get_X();
    unsigned int get_Y();
    void resetLife();
    virtual void setLife(int damage, Player* attacker);
    virtual void createUnit(int typeUnit);
    virtual ~Building();
};

#endif // BUILDING_H
