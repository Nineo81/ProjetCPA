#ifndef RECON_H
#define RECON_H
#include "unit.h"


class Recon : public Unit
{
public:
    Recon(vector<unsigned int> pos,int color, int round,Game *game);
};

#endif // RECON_H
