#ifndef UNIT_H
#define UNIT_H
#include "gameobject.h"
#include <string>
#include <vector>
using namespace std;


class Unit : public GameObject
{
private:
    int color;
    int round;
    vector<vector<int>> *DC; //pointeur vers defenseChart




protected:
    int HP;
    int cost;
    string move_type;
    int range[2];
    int absMP;
    int MP;
    int type;




public:
    Unit(int pos[2], int color, int round, vector<vector<int>> *DC);
    int getHP() const;          //fait
    void setHP(int newHP,char sign);//fait
    void setHP();                   //fait
    int getcolor() const;        //fait
    int getcost() const;      //fait
    int getround() const;   //fait
    void setround(); //fait
    int gettype() const; //fait
    vector<vector<int>> *getDC();
    int move();
    void join_unit(Unit Unit2);
    int getMP() const; //fait
    void setMP(int newMP); //fait
    void resetMP();   //fait
    int damage(Unit defender);  //fait
    int find_B(Unit defender); //fait
    int get_D_TR();             //fait
    void attack(Unit defender); //fait
};

#endif // UNIT_H
