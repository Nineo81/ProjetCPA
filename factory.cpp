#include "factory.h"
#include "antiair.h"
#include "bazooka.h"
#include "infantery.h"
#include "mdtank.h"
#include "megatank.h"
#include "neotank.h"
#include "recon.h"
#include "tank.h"



Factory::Factory(vector<unsigned int> pos, Player* player,Game *game):Building (pos, player)
{
    type = 35;
    this->game = game;
    this->player = player;
}

Factory::Factory(vector<unsigned int> pos,Game *game):Building (pos){
    type = 35;
    this->game = game;
    player = NULL;
}

void Factory::createUnit(int typeUnit){
    Unit *unit = nullptr;
    switch (typeUnit)
    {
        case 1:{
            unit = new infantery(this->position,player->getPlayerNumber(),0,game);      //c'est quoi l'attribut round?
            break;}
        case 2:{
            unit = new Bazooka(this->position,player->getPlayerNumber(),0,game);
            break;}
        case 3:{
            unit = new Recon(this->position,player->getPlayerNumber(),0,game);
            break;}
        case 4:{
            unit = new AntiAir(this->position,player->getPlayerNumber(),0,game);
            break;}
        case 5:{
            unit = new Tank(this->position,player->getPlayerNumber(),0,game);
            break;}
        case 6:{
            unit = new mdtank(this->position,player->getPlayerNumber(),0,game);
            break;}
        case 7:{
            unit = new megatank(this->position,player->getPlayerNumber(),0,game);
            break;}
        case 8:{
            unit = new neotank(this->position,player->getPlayerNumber(),0,game);
            break;}
    }
    this->player->set_money(unit->getcost(),'d');
    player->add_unit(unit);
    if (this->player->get_money()<0){
        this->player->set_money(unit->getcost(),'a');
        delete unit;
    }
}

void Factory::setLife(int damage, Player* attacker){
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
        if (attacker == game->getPlayer(1))
        {
            game->getTerrainMap().setElement(39,position[0],position[1]);
        }
        else if (attacker == game->getPlayer(2))
        {
            game->getTerrainMap().setElement(44,position[0],position[1]);
        }
    }
    else {life = temp;}
}

Factory::~Factory(){}
