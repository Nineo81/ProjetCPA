#include "player.h"

Player::Player(vector<Building*> firstBuildings)
{
    this->listBuilding=firstBuildings;
    this->money=1000*(this->listBuilding.size());
    for (int i = 0;i<listBuilding.size();i++){
        listBuilding[i]->setPlayer(this);
    }
}

int Player::get_money(){
    return this->money;
}

void Player::set_money(int diff, char sign){
    if (sign =='d'){
        this->money -= diff;}
    else if (sign == 'a') {
        this->money += diff;
    }
}

void Player::add_building(Building* building){
    this->listBuilding.push_back(building);
}
