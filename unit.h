#ifndef UNIT_H
#define UNIT_H
#include "gameobject.h"
#include <string>
using namespace std;


class Unit : public GameObject
{
private:
    int color;
    int life_points;
    int round;
    int cost;
    int type;
    string move_type;
    int range[2];

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
