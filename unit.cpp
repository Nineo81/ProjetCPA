#include "unit.h"
#include <string>
#include <iostream>
#include "terrain.h"
#include "game.h"

using namespace std;


Unit::Unit(int pos[2], int color, int round, vector<vector<int>> *DC) : GameObject(pos)
{
    this->color=color;
    this->round=round;
    this->HP=10;
    this->DC=DC;
}


int Unit::getHP() const
{
    return this->HP;
}

void Unit::setHP()
{
    this->HP=10;
}

void Unit::setHP(int newHP,char sign)
{
    if (sign=='a')
        this->HP+=newHP;
    else if (sign=='d')
        this->HP-=newHP;
    else
        cout<<"Erreur caractère dans setHP non incorrect."<<endl;
}

vector<vector<int>> *Unit::getDC()
{
    return this->DC;
}

int Unit::getcolor() const
{
    return this->color;
}

int Unit::getcost() const
{
    return this->cost;
}

int Unit::getround() const
{
    return this->round;
}

void Unit::setround()
{
    this->round+=1;
}

int Unit::getMP() const
{
    return this->MP;
}

void Unit::setMP(int MPloss)
{
    this->MP-=MPloss;
}

void Unit::resetMP()
{
    this->MP=this->absMP;
}

int Unit::gettype() const
{
    return this->type;
}


int Unit::find_B(Unit defender)
{
    int damage_chart[11][11]={{45,120,105,75,65,105,10,1,5,60,25},  //Lignes:attaquant
                           {25,65,75,0,0,75,25,10,20,55,55},    //Colonnes:défense
                           {65,9,55,0,0,65,15,5,15,85,55},
                           {95,0,110,0,0,110,95,35,90,105,105},
                           {0,100,0,100,55,0,0,0,0,0,0},
                           {5,15,45,0,0,55,1,1,112,5},
                           {105,12,95,0,0,105,55,25,45,105,85},
                           {195,22,125,0,0,135,125,65,115,195,180},
                           {115,22,115,0,0,125,75,35,55,125,105},
                           {4,12,65,0,0,70,1,1,1,35,6},
                           {65,10,70,0,0,75,15,10,15,85,55}};

    int B=damage_chart[this->gettype()][defender.gettype()];
    return B;
}

int Unit::get_D_TR()
{
    int X=this->get_X();
    int Y=this->get_Y();
    vector<vector<int>> *DC=this->getDC();
    vector<vector<int>> defenseChart= *DC;
    int D_TR=defenseChart[X][Y];
    return 0;
}

int Unit::damage(Unit defender)
{

    int A_HP=this->HP;
    int D_HP=defender.getHP();
    int B=find_B(defender);
    int D_TR=this->get_D_TR();
    int damage=(B*A_HP/10*(100-D_TR*D_HP)/100)+0.5; /*ajout de 0,5 pour être sûr que
                                                      *damage est arrondi aux bonnes valeurs
                                                      * c++ arrondi tjs en-dessous*/

    return damage;
}

void Unit::attack(Unit defender)
{
    int damage=this->damage(defender);
    defender.setHP(damage,'d');
}

void Unit::join_unit(Unit unit2)
{
    unit2.setHP(this->getHP(),'a');
    if (unit2.getHP()>10)
        unit2.setHP();               //si HP de unit2 >10 : on arrondi son HP à 10
    delete this;                     //auto-destruction de l'unité pour que les 2 unités deviennent un
}

