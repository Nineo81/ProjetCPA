#include "city.h"

City::City(int pos[2],int color, Player* player):Building(pos, color)  //changer l'apparence
{
    this->player = player;
}

void City::setLife(int damage, Player* attacker){
    int temp = life - damage;
    if (temp <= 0){
        City* building = new City(this->position,0,attacker);
        attacker->add_building(building);
        //changer l'affichage aussi??
        delete this;
    }
    else {life = temp;}
}
