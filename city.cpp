#include "city.h"

City::City(vector<unsigned int> pos,Player* player, Game * game):Building(pos, player)
{
    type = 34;
    this->game = game;
    this->player = player;
}

City::City(vector<unsigned int> pos, Game * game):Building (pos){
    type = 34;
    this->game =game;
    player = NULL;
}

void City::setLife(int damage, Player* attacker){
    int temp = life - damage;
    if (temp <= 0){
        if (player != NULL)
        {
            player->delete_building(this);
        }
        else {
            game->delete_building(this);
        }
        attacker->add_building(this);
        this->setPlayer(attacker);
        this->life = 20;
        if (attacker==game->getPlayer(1))
        {
            game->getTerrainMap().setElement(38,position[0],position[1]);
        }
        else if (attacker==game->getPlayer(2))
        {
            game->getTerrainMap().setElement(43,position[0],position[1]);
        }
    }
    else {life = temp;}
}

void City::createUnit(int typeUnit){}
