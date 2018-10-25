#ifndef FACTORY_H
#define FACTORY_H
#include "building.h"

class Factory:public Building
{
public:
    Factory(int pos[2]);
    Unit createUnit(int typeUnit);   //changer le nom du type selon
    //je sais pas si c'est mieux de renvoyer un pointeur ou une unite, a voir
};

#endif // FACTORY_H
