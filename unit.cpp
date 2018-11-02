#include "unit.h"

Unit::Unit(int pos[2], int color, int round) : GameObject(pos)
{
    this->color=color;
    this->round=round;
    this->HP=10;
}

int Unit::getHP() const
{
    return this->HP;
}

void Unit::settHP(int HPloss)
{
    this->HP-=HPloss;
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
    int ta=this->gettype();
    int td=defender.gettype();
   // int damage_chart[11][11]= *pdc;
    //int B=damage_chart[ta][td];
    //return B;
}

int Unit::damage(Unit defender)
{
    int A_HP=this->HP;
    int D_TR;
    int D_HP=defender.getHP();
    int damage;
    return damage;

}
