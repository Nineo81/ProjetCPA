#include "mdtank.h"

mdtank::mdtank(vector<unsigned int> pos,int color, int round,Game *game):Unit(pos, color, round,game)
{
    this->type=51;
    this->absMP=5;
    this->MP=this->absMP;
    this->cost=16000;
    this->move_type=2;
    this->attack_type=6;

}
