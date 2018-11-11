#ifndef BUILDING_H
#define BUILDING_H
#include "terrain.h"

class Player;
class Building:public Terrain
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
};

#endif // BUILDING_H
