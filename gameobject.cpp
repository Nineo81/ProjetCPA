#include "gameobject.h"

GameObject::GameObject(std::vector<unsigned int> pos)
{
    position.push_back(pos[0]);
    position.push_back(pos[1]);
}
unsigned int GameObject::get_X() const
{
    return position[0];
}

unsigned int GameObject::get_Y() const
{
    return position[1];
}
 void GameObject::setposition(std::vector<unsigned int> newPos)
 {
     position[0] = newPos[0];
     position[1] = newPos[1];
 }
