#include "unit.h"
#include <string>
#include <iostream>
#include "terrain.h"
#include "game.h"


using namespace std;


Unit::Unit(int pos[2], int color, int round, vector<vector<int>> *PDC, Map *PTM) : GameObject(pos)
{
    this->color=color;
    this->round=round;
    this->HP=10;
    this->PDC=PDC;
    this->PTM=PTM;
}


int Unit::getHP() const
{
    return this->HP;
}

void Unit::setHP()
{
    this->HP=10;
}

void Unit::setHP(int newHP,char sign)
{
    if (sign=='a')
        this->HP+=newHP;
    else if (sign=='d')
        this->HP-=newHP;
    else
        cout<<"Erreur caractère dans setHP non incorrect."<<endl;
}

vector<vector<int>> Unit::getDefenseChart() const
{
    return *PDC;
}

Map Unit::getTerrainMap() const
{
    return *PTM;
}

int Unit::getcolor() const
{
    return this->color;
}

int Unit::getcost() const
{
    return this->cost;
}

int Unit::getround() const
{
    return this->round;
}

void Unit::setround()
{
    this->round+=1;
}

int Unit::getMP() const
{
    return this->MP;
}

void Unit::setMP(int MPloss)
{
    this->MP-=MPloss;
}

void Unit::resetMP()
{
    this->MP=this->absMP;
}

int Unit::gettype() const
{
    return this->type;
}

int Unit::getMoveType() const
{
    return this->move_type;
}

int Unit::find_B(Unit defender)
{
    int damage_chart[11][11]={{45,120,105,75,65,105,10,1,5,60,25},  //Lignes:attaquant
                           {25,65,75,0,0,75,25,10,20,55,55},    //Colonnes:défense
                           {65,9,55,0,0,65,15,5,15,85,55},
                           {95,0,110,0,0,110,95,35,90,105,105},
                           {0,100,0,100,55,0,0,0,0,0,0},
                           {5,15,45,0,0,55,1,1,112,5},
                           {105,12,95,0,0,105,55,25,45,105,85},
                           {195,22,125,0,0,135,125,65,115,195,180},
                           {115,22,115,0,0,125,75,35,55,125,105},
                           {4,12,65,0,0,70,1,1,1,35,6},
                           {65,10,70,0,0,75,15,10,15,85,55}};

    int B=damage_chart[this->gettype()][defender.gettype()];
    return B;
}

int Unit::get_D_TR()
{
    int X=this->get_X();
    int Y=this->get_Y();
    vector<vector<int>> defenseChart=this->getDefenseChart();
    int D_TR=defenseChart[X][Y];
    return D_TR;
}

int Unit::damage(Unit defender)
{

    int A_HP=this->HP;
    int D_HP=defender.getHP();
    int B=find_B(defender);
    int D_TR=this->get_D_TR();
    int damage=(B*A_HP/10*(100-D_TR*D_HP)/100)+0.5; /*ajout de 0,5 pour être sûr que
                                                      *damage est arrondi aux bonnes valeurs
                                                      * c++ arrondi tjs en-dessous*/
    return damage;
}

void Unit::attack(Unit defender)
{
    int damage=this->damage(defender);
    defender.setHP(damage,'d');
}

void Unit::join_unit(Unit unit2)
{
    unit2.setHP(this->getHP(),'a');
    if (unit2.getHP()>10)
        unit2.setHP();               //si HP de unit2 >10 : on arrondi son HP à 10
    delete this;                     //auto-destruction de l'unité pour que les 2 unités deviennent un
}

int Unit::get_MPLoss(int x, int y)
{
    int terrainChart[11][5]={{1,1,1,2,1},
                             {2,1,0,0,1},
                             {1,1,2,3,1},
                             {2,1,0,0,1},
                             {1,1,1,1,1},
                             {0,0,0,0,1},
                             {1,1,1,1,1},
                             {0,0,0,0,1},
                             {1,1,1,1,1},
                             {1,1,1,1,1},
                             {0,0,0,0,0}};
    Map terrainMap=this->getTerrainMap();
    int temp=terrainMap.getElement(x,y);
    int terrainType=0;
    if (temp==1)
        terrainType=0;
    else if(temp==2)
        terrainType=1;
    else if(temp==3)
        terrainType=2;
    else if(temp==10 || temp==11 || temp==12 || temp==4 || temp==5 ||
            temp==6 || temp==7 || temp==8 || temp==9 || temp==13 || temp==14)
        terrainType=3;
    else if(temp==15 || temp==16 || temp==17 || temp==18 || temp==19 ||
            temp==20 || temp==21 || temp==22 || temp==23 || temp==24 ||
            temp==25)
        terrainType=4;
    else if(temp==28)
        terrainType=5;
    else if(temp==29 || temp==30 || temp==31 || temp==32)
        terrainType=6;
    else if(temp==33)
        terrainType=7;
    else if(temp==34 || temp==38 || temp==43)
        terrainType=8;
    else if(temp==35 || temp==39 || temp==44)
        terrainType=9;
    else if(temp==101 || temp==102 || temp==103 || temp==104 || temp==105 || temp==106 || temp==107 || temp==108 || temp==109 || temp==110)
        terrainType=10;
    return terrainChart[terrainType][this->getMoveType()];
}

//vector<vector<int>> Unit::movePossib(int x,int y)
//{
//    int MPLoss=this->get_MPLoss(x,y);       //à terminer
//}
