#include "bazooka.h"

Bazooka::Bazooka(int pos[2],int color, int round,vector<vector<int>> *DC):Unit(pos, color, round,DC)
{
    this->type=2;
    this->move_type=1;
}
