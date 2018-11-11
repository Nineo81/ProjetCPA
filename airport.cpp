#include "airport.h"
#include "b_copter.h"
#include "bomber.h"
#include "fighter.h"

Airport::Airport(int pos[2], Player* player):Building (pos, player)
{
    type = 36;
}

Airport::Airport(int pos[2]):Building(pos){
    type = 36;
}

AirUnit* Airport::createUnit(int typeUnit){
    AirUnit* unit = NULL;
    switch (typeUnit)
    {
        case 1:{
            unit = new B_Copter(this->position,this->color,0);      //c'est quoi l'attribut round?
            break;}
        case 2:{
            unit = new Fighter(this->position,this->color,0);
            break;}
        case 3:{
            unit = new Bomber(this->position,this->color,0);
            break;}
    }
    this->player->set_money(unit->getcost(),'d');
    if (this->player->get_money()<0){
        this->player->set_money(unit->getcost(),'a');
        delete unit;
        return NULL;
    }
    else{return unit;}
}

void Airport::setLife(int damage, Player* attacker){
    int temp = life - damage;
    if (temp <= 0){
        //this->player->removeBuilding(this);
        attacker->add_building(this);
        this->life = 20;
    }
    else {life = temp;}
}
