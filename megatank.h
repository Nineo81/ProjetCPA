#ifndef MEGATANK_H
#define MEGATANK_H
#include "unit.h"


class megatank : public Unit
{
public:
    megatank(int pos[2],int color, int round,vector<vector<int>> *TDC,Map *PTM);
};

#endif // MEGATANK_H
