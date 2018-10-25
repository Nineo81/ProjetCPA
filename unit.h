#ifndef UNIT_H
#define UNIT_H
#include "gameobject.h"


class Unit : public GameObject
{
private:
    int color;
    int life_points;
    int round;
    int cost;
    int type;
public:
    Unit();
    int getlife_points();
    void setlife_points(int);
    int getcolor();
    int getcost();
    int getround();
    void setround(int);
    int gettype();
    int move();

};

#endif // UNIT_H
