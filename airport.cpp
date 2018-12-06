#include "airport.h"
#include "b_copter.h"
#include "bomber.h"
#include "fighter.h"

Airport::Airport(int pos[2], Player* player,Game *game):Building (pos, player)
{
    this->game=game;
    type = 36;
}

Airport::Airport(int pos[2],Game *game):Building(pos){
    type = 36;
    this->game=game;
}

void Airport::createUnit(int typeUnit){
    AirUnit* unit = nullptr;
    switch (typeUnit)
    {
        case 1:{
            unit = new B_Copter(this->position,this->color,0,game);      //c'est quoi l'attribut round?
            break;}
        case 2:{
            unit = new Fighter(this->position,this->color,0,game);
            break;}
        case 3:{
            unit = new Bomber(this->position,this->color,0,game);
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
        this->player->delete_building(this);
        attacker->add_building(this);
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
