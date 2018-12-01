#include "airport.h"
#include "b_copter.h"
#include "bomber.h"
#include "fighter.h"

Airport::Airport(int pos[2], Player* player,vector<vector<int>> *DC,Map *PTM):Building (pos, player)
{
    type = 36;
    this->DC = DC;
    this->PTM=PTM;
}

Airport::Airport(int pos[2],vector<vector<int>> *DC,Map *PTM):Building(pos){
    type = 36;
    this->DC = DC;
    this->PTM=PTM;
}

void Airport::createUnit(int typeUnit){
    AirUnit* unit = nullptr;
    switch (typeUnit)
    {
        case 1:{
            unit = new B_Copter(this->position,this->color,0,DC,PTM);      //c'est quoi l'attribut round?
            break;}
        case 2:{
            unit = new Fighter(this->position,this->color,0,DC,PTM);
            break;}
        case 3:{
            unit = new Bomber(this->position,this->color,0,DC,PTM);
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
    }
    else {life = temp;}
}

Airport::~Airport(){}
