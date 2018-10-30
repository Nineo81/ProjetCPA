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
