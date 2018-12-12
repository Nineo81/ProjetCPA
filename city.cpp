#include "city.h"

City::City(vector<unsigned int> pos,Player* player):Building(pos, player)
{
    type = 34;
}

City::City(vector<unsigned int> pos):Building (pos){
    type = 34;
}

void City::setLife(int damage, Player* attacker){
    int temp = life - damage;
    if (temp <= 0){
        this->player->delete_building(this);
        attacker->add_building(this);
        this->setPlayer(attacker);
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
