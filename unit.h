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
    int* pdc;


protected:
    int HP;
    int cost;
    string move_type;
    int range[2];
    int absMP;
    int MP;
    int type;



public:
    Unit(int pos[2], int color, int round);
    int getHP() const;          //fait
    void settHP(int newHP);//fait
    int getcolor() const;        //fait
    int getcost() const;      //fait
    int getround() const;   //fait
    void setround(); //fait
    int gettype() const;
    int move();
    void join_unit();
    int getMP() const; //fait
    void setMP(int newMP); //fait
    void resetMP();   //fait
    int damage(Unit defender);
    int find_B(Unit defender);


};

#endif // UNIT_H
