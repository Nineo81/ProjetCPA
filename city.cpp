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
        if (attacker==Game->getPlayer(1))
        {
            Game->getTerrainMap().setElement(38,position[0],position[1]);
        }
        else if (attacker==Game->getPlayer(2))
        {
            Game->getTerrainMap().setElement(43,position[0],position[1]);
        }
    }
    else {life = temp;}
}

void City::createUnit(int typeUnit){}
