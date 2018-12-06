#include "bazooka.h"

Bazooka::Bazooka(int pos[2],int color, int round,Game * game):Unit(pos, color, round,game)
{
    this->type=58;
    this->move_type=1;
}
