#include "recon.h"

Recon::Recon(vector<unsigned int> pos,int color, int round,Game *game):Unit(pos, color, round,game)
{
    this->type = 54;
    this->absMP = 8;
    this->MP = this->absMP;
    this->cost = 4000;
    this->move_type = 3;
    this->attack_type = 9;
    setUnit();

}
