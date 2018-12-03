#include "gameobject.h"

GameObject::GameObject(int pos[2])
{
    position[0]=pos[0];
    position[1]=pos[1];
}
int GameObject::get_X() const
{
    return position[0];
}

int GameObject::get_Y() const
{
    return position[1];
}
 void GameObject::setposition(int newposition[2])
 {
     position[0]=newposition[0];
     position[1]=newposition[1];
 }
