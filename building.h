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
    int position[2];
public:
    Building(int pos[2], Player* player);
    Building(int pos[2]);
    int getLife() const;
    void setPlayer(Player* player);
    int getType() const;
    int get_X();
    int get_Y();
    void setposition(int newposition[2]);
    virtual void createUnit(int typeUnit);
    virtual ~Building();
};

#endif // BUILDING_H
