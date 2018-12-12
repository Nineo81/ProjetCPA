#include "infantery.h"
#include <iostream>
using std::cout;
using std::endl;


infantery::infantery(vector<unsigned int> pos,int color, int round, Game* game):Unit(pos, color, round,game)
{
    this->type=50;
    this->absMP=3;
    this->MP=this->absMP;
    this->cost=1000;
    this->move_type=0;
    this->attack_type=5;
    setUnit();
}
