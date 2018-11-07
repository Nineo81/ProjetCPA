#ifndef FACTORY_H
#define FACTORY_H
#include "building.h"
#include "unit.h"

class Factory:public Building
{
public:
    Factory(int pos[2], int app);
    Unit createUnit(int typeUnit);   //changer le nom du type selon
    //je sais pas si c'est mieux de renvoyer un pointeur ou une unite, a voir

private:
    int typeUnit;
};

#endif // FACTORY_H
