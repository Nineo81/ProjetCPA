#ifndef AIRPORT_H
#define AIRPORT_H
#include "building.h"

class Airport:public Building
{
public:
    Airport(int pos[2]);
    //Plane createUnit(int typeUnit);   //changer le nom du type selon
    //je sais pas si c'est mieux de renvoyer un pointeur ou une unite, a voir
};

#endif // AIRPORT_H
