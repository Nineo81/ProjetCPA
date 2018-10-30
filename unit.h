#ifndef UNIT_H
#define UNIT_H
#include "gameobject.h"
#include <string>
using namespace std;


class Unit : public GameObject
{
private:
    int color;
    int round;
    int type;


protected:
    int HP;
    int cost;
    string move_type;
    int range[2];
    int absMP;
    int MP;


public:
    Unit(int pos[2], int color, int round);
    int getHP() const;          //fait
    void settHP(int newHP);//fait
    int getcolor() const;        //fait
    int getcost() const;      //fait
    int getround() const;   //fait
    void setround(); //fait
    int gettype() const;  //je sais plus à quoi sert type....
    int move();
    void join_unit();
    int getMP() const;
    void setMP(int newMP);
    void resetMP();   //fait


};

#endif // UNIT_H
