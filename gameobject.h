#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <iostream>


class GameObject
{
protected:
    int position[2];
public:
    GameObject(int pos[2]);
    int get_X() const;
    int get_Y() const;
    void setposition(int newposition[2]);
};

#endif // GAMEOBJECT_H
