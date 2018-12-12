#include "bazooka.h"

Bazooka::Bazooka(vector<unsigned int> pos,int color, int round,Game * game):Unit(pos, color, round,game)
{
    this->type=58;
    this->move_type=1;
    this->attack_type=2;
}
