#include "factory.h"
#include "antiair.h"
#include "bazooka.h"
#include "infantery.h"
#include "mdtank.h"
#include "megatank.h"
#include "neotank.h"
#include "recon.h"
#include "tank.h"



Factory::Factory(int pos[2], Player* player,vector<vector<int>> *DC,Map *PTM,Map *PUM):Building (pos, player)
{
    type = 35;
    this->DC = DC;
    this->PTM=PTM;
    this->PUM=PUM;
}

Factory::Factory(int pos[2],vector<vector<int>> *DC,Map *PTM,Map *PUM):Building (pos){
    type = 35;
    this->DC = DC;
    this->PTM=PTM;
    this->PUM=PUM;
}

void Factory::createUnit(int typeUnit){
    Unit *unit = nullptr;
    switch (typeUnit)
    {
        case 1:{
            unit = new infantery(this->position,player->getPlayerNumber(),0,DC,PTM,PUM);      //c'est quoi l'attribut round?
            break;}
        case 2:{
            unit = new Bazooka(this->position,player->getPlayerNumber(),0,DC,PTM,PUM);
            break;}
        case 3:{
            unit = new Recon(this->position,player->getPlayerNumber(),0,DC,PTM,PUM);
            break;}
        case 4:{
            unit = new AntiAir(this->position,player->getPlayerNumber(),0,DC,PTM,PUM);
            break;}
        case 5:{
            unit = new Tank(this->position,player->getPlayerNumber(),0,DC,PTM,PUM);
            break;}
        case 6:{
            unit = new mdtank(this->position,player->getPlayerNumber(),0,DC,PTM,PUM);
            break;}
        case 7:{
            unit = new megatank(this->position,player->getPlayerNumber(),0,DC,PTM,PUM);
            break;}
        case 8:{
            unit = new neotank(this->position,player->getPlayerNumber(),0,DC,PTM,PUM);
            break;}
    }
    this->player->set_money(unit->getcost(),'d');
    if (this->player->get_money()<0){
        this->player->set_money(unit->getcost(),'a');
        delete unit;
    }
    else
    {
        player->add_unit(unit);
    }
}

void Factory::setLife(int damage, Player* attacker){
    int temp = life - damage;
    if (temp <= 0){
        this->player->delete_building(this);
        attacker->add_building(this);
        this->life = 20;
        if (attacker==Game->getPlayer(1))
        {
            Game->getTerrainMap().setElement(39,position[0],position[1]);
        }
        else if (attacker==Game->getPlayer(2))
        {
            Game->getTerrainMap().setElement(44,position[0],position[1]);
        }
    }
    else {life = temp;}
}

Factory::~Factory(){}
