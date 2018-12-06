#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <iostream>
#include <vector>

class GameObject
{
protected:
    std::vector<unsigned int> position;
public:
    GameObject(std::vector<unsigned int> pos);
    unsigned int get_X() const;
    unsigned int get_Y() const;
    void setposition(std::vector<unsigned int> newPos);
};

#endif // GAMEOBJECT_H
