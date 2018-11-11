#include "airport.h"
#include "b_copter.h"
#include "bomber.h"
#include "fighter.h"

Airport::Airport(int pos[2], Player* player,vector<vector<int>> *DC):Building (pos, player)
{
    type = 36;
    this->DC = DC;
}

Airport::Airport(int pos[2],vector<vector<int>> *DC):Building(pos){
    type = 36;
    this->DC = DC;
}

AirUnit* Airport::createUnit(int typeUnit){
    AirUnit* unit = NULL;
    switch (typeUnit)
    {
        case 1:{
            unit = new B_Copter(this->position,this->color,0,DC);      //c'est quoi l'attribut round?
            break;}
        case 2:{
            unit = new Fighter(this->position,this->color,0,DC);
            break;}
        case 3:{
            unit = new Bomber(this->position,this->color,0,DC);
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
        this->player->delete_building(this);
        attacker->add_building(this);
        this->life = 20;
    }
    else {life = temp;}
}
