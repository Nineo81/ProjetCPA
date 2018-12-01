#ifndef BUILDING_H
#define BUILDING_H
#include "gameobject.h"

class Player;
class Building:public GameObject
{
protected:
    int life;
    int color;
    Player* player;
    int type;
public:
    Building(int pos[2], Player* player);
    Building(int pos[2]);
    int getLife() const;
    void setPlayer(Player* player);
    int getType() const;
    void setposition(int newposition[2]);
};

#endif // BUILDING_H
