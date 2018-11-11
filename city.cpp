#include "city.h"

City::City(int pos[2],Player* player):Building(pos, player)  //changer l'apparence
{
    type = 34;
}

City::City(int pos[2]):Building (pos){
    type = 34;
}

void City::setLife(int damage, Player* attacker){
    int temp = life - damage;
    if (temp <= 0){
        this->player->delete_building(this);
        attacker->add_building(this);
        this->life = 20;
    }
    else {life = temp;}
}
