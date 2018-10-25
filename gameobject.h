#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <iostream>


class GameObject
{
private:
    int position; //la position srait donnée par le pointeur du tableau de position [x,y]
public:
    GameObject();
    int getposition();
    void setposition(int newposition[]);
};

#endif // GAMEOBJECT_H
