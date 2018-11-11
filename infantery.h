#ifndef INFANTERY_H
#define INFANTERY_H
#include "unit.h"

class infantery : public Unit
{
public:
    infantery(int pos[2],int color, int round,vector<vector<int>> *DC);
};

#endif // INFANTERY_H
