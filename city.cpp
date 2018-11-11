#include "city.h"

City::City(int pos[2],Player* player):Building(pos, player)  //changer l'apparence
{

}

City::City(int pos[2]):Building (pos){

}

void City::setLife(int damage, Player* attacker){
    int temp = life - damage;
    if (temp <= 0){
        City* building = new City(this->position,attacker);
        attacker->add_building(building);
        //changer l'affichage aussi??
        delete this;
    }
    else {life = temp;}
}
