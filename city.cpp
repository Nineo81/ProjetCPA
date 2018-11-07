#include "city.h"

City::City(int pos[2],int color, Player* player):Building(pos, color)  //changer l'apparence
{
    this->player = player;
}
