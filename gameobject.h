#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <iostream>


class GameObject
{
private:
    int position[];
public:
    GameObject();
    int getposition();
    void setposition(int newposition[]);
};

#endif // GAMEOBJECT_H
