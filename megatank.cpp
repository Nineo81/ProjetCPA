#include "megatank.h"

megatank::megatank(vector<unsigned int> pos,int color, int round,Game *game):Unit(pos, color, round,game)
{
    this->type=52;
    this->absMP=4;
    this->MP=this->absMP;
    this->cost=28000;
    this->move_type=2;
    this->attack_type=7;

}
