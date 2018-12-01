#include "factory.h"
#include "antiair.h"
#include "bazooka.h"
#include "infantery.h"
#include "mdtank.h"
#include "megatank.h"
#include "neotank.h"
#include "recon.h"
#include "tank.h"



Factory::Factory(int pos[2], Player* player,vector<vector<int>> *DC,Map *PTM):Building (pos, player)
{
    type = 35;
    this->DC = DC;
    this->PTM=PTM;
}

Factory::Factory(int pos[2],vector<vector<int>> *DC,Map *PTM):Building (pos){
    type = 35;
    this->DC = DC;
    this->PTM=PTM;
}

void Factory::createUnit(int typeUnit){
    Unit *unit = nullptr;
    switch (typeUnit)
    {
        case 1:{
            unit = new infantery(this->position,this->color,0,DC,PTM);      //c'est quoi l'attribut round?
            break;}
        case 2:{
            unit = new Bazooka(this->position,this->color,0,DC,PTM);
            break;}
        case 3:{
            unit = new Recon(this->position,this->color,0,DC,PTM);
            break;}
        case 4:{
            unit = new AntiAir(this->position,this->color,0,DC,PTM);
            break;}
        case 5:{
            unit = new Tank(this->position,this->color,0,DC,PTM);
            break;}
        case 6:{
            unit = new mdtank(this->position,this->color,0,DC,PTM);
            break;}
        case 7:{
            unit = new megatank(this->position,this->color,0,DC,PTM);
            break;}
        case 8:{
            unit = new neotank(this->position,this->color,0,DC,PTM);
            break;}
    }
    this->player->set_money(unit->getcost(),'d');
    if (this->player->get_money()<0){
        this->player->set_money(unit->getcost(),'a');
        delete unit;
    }
}

void Factory::setLife(int damage, Player* attacker){
    int temp = life - damage;
    if (temp <= 0){
        this->player->delete_building(this);
        attacker->add_building(this);
        this->life = 20;
    }
    else {life = temp;}
}

Factory::~Factory(){}
