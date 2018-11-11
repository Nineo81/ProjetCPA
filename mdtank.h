#ifndef MDTANK_H
#define MDTANK_H
#include"unit.h"


class mdtank : public Unit
{
public:
    mdtank(int pos[2],int color, int round,vector<vector<int>> *DC);
};

#endif // MDTANK_H
