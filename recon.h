#ifndef RECON_H
#define RECON_H
#include "unit.h"


class Recon : public Unit
{
public:
    Recon(int pos[2],int color, int round,vector<vector<int>> *TDC,Map *PTM);
};

#endif // RECON_H
