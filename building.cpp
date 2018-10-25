#include "building.h"

Building::Building(int pos[2],int app):Terrain (pos,3,app)
{
    life = 20;
}

int Building::getLife() const{
    return life;
}

void Building::changeLife(int damage){       //plutot que faire des degats, peut aller chercher la vie de l'unité dessus
                                            //rajouter un while(pos unite = pos bat) => vie doit revenir à 20 sinon
    int temp = life - damage;
    if (temp <= 0){
        //le batiment doit changer de joueur
        life = 20; //et la vie est de nouveau max
    }
    else {life = temp;}
}
