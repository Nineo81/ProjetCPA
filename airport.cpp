#include "airport.h"
#include "b_copter.h"
#include "bomber.h"
#include "fighter.h"

Airport::Airport(vector<unsigned int> pos, Player* player,Game *game):Building (pos, player)
{
    this->game=game;
    type = 36;
    this->player = player;
}

Airport::Airport(vector<unsigned int> pos,Game *game):Building(pos){
    type = 36;
    this->game=game;
    player = NULL;
}

void Airport::createUnit(int typeUnit){
    AirUnit* unit = nullptr;
    switch (typeUnit)
    {
        case 9:{
            unit = new B_Copter(this->position,player->getPlayerNumber(),0,game);      //c'est quoi l'attribut round?
            break;}
        case 10:{
            unit = new Fighter(this->position,player->getPlayerNumber(),0,game);
            break;}
        case 11:{
            unit = new Bomber(this->position,player->getPlayerNumber(),0,game);
            break;}
    }
    this->player->set_money(unit->getcost(),'d');
    if (this->player->get_money()<0){
        this->player->set_money(unit->getcost(),'a');
        delete unit;
    }
}

void Airport::setLife(int damage, Player* attacker){
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
            game->getTerrainMap().setElement(40,position[0],position[1]);
        }
        else if (attacker==game->getPlayer(2))
        {
            game->getTerrainMap().setElement(45,position[0],position[1]);
        }
    }
    else {life = temp;}
}

Airport::~Airport(){}
