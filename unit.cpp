#include "unit.h"
#include <string>
#include <iostream>
#include<algorithm>
#include<cmath>
#include "game.h"
using std::sort;
using std::cout;
using std::endl;


using namespace std;


bool Unit::getCanPlay() const
{
    return canPlay;
}

void Unit::setCanPlay(bool value)
{
    canPlay = value;
}

void Unit::setBestPath(const vector<vector<int> > value)
{
    bestPath = value;
}

vector<vector<int>> Unit::getBestPath()
{
    return bestPath;
}

vector<vector<int>>* Unit::getPBP()
{
    return &bestPath;
}

Unit::Unit(std::vector<unsigned int> pos, int color, int round,Game *game) : GameObject(pos)
{
    this->game=game;
    this->color=color;
    this->round=round;
    this->HP=10;
    this->type=5;
    this->PDC=game->getDefenseChart();
    this->PTM=game->getPTM();
    this->PUM=game->getPUM();
    this->canPlay=false;
}



void Unit::setUnit()
{
    if (color==1)
    game->updateMap(this->type,this->position[0],this->position[1]);

    else
     { this->type=type+11;
        game->updateMap(this->type,this->position[0],this->position[1]);

    }
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
    {
        this->HP+=newHP;
        if (HP>10)
        {
            setHP();
        }
     }
    else if (sign=='d')
    {
        this->HP-=newHP;
        if (HP<=0)
        {
            delete this;
        }
    }
    else
        cout<<"Erreur caractère dans setHP non incorrect."<<endl;
}

vector<vector<int>> Unit::getDefenseChart() const
{
    return *PDC;
}

Map* Unit::getTerrainMap() const
{
    return PTM;
}

Map* Unit::getUnitMap() const
{
    return PUM;
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

int Unit::getAttackType() const
{
    return this->attack_type;
}

int Unit::get_absMP() const
{
    return this->absMP;
}

int Unit::find_B(Unit* defender)
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

    int B=damage_chart[this->getAttackType()][defender->getAttackType()];
    return B;
}


int Unit::get_D_TR() const
{
    unsigned int X=this->get_X();
    unsigned int Y=this->get_Y();
    vector<vector<int>> defenseChart=this->getDefenseChart();
    int D_TR;
    if (this->gettype()==56 || this->gettype()==57 || this->gettype()==59)
    {
        D_TR=0;
    }
    else
    {
        D_TR=defenseChart[X][Y];
    }
    return D_TR;
}

int Unit::damage(Unit* defender)
{

    int A_HP=this->HP;
    int D_HP=defender->getHP();
    int B=find_B(defender);
    int D_TR=this->get_D_TR();
    int damage=static_cast<int>(((B*A_HP/10*(100-D_TR*D_HP)/100)/10)+0.5); /*ajout de 0,5 pour être sûr que
                                                      *damage est arrondi aux bonnes valeurs
                                                      * c++ arrondi tjs en-dessous*/
    return damage;
}

void Unit::attack(Unit* defender)
{
    unsigned int posX_D=defender->get_X();
    unsigned int posY_D=defender->get_Y();
    int damage=this->damage(defender);
    defender->setHP(damage,'d');
    if(this->getUnitMap()->getElement(posX_D,posY_D)!=0)
    {
        int damage2=defender->damage(this);
        this->setHP(damage2,'d');
        canPlay = false;
    }
}

void Unit::join_unit(Unit* unit2)
{
    unit2->setHP(this->getHP(), 'a');
    if (unit2->getHP() > 10)
        unit2->setHP();               //si HP de unit2 >10 : on arrondi son HP à 10
    delete this;                     //auto-destruction de l'unité pour que les 2 unités deviennent un
}

int Unit::get_MPLoss(unsigned int x, unsigned int y)
{
    int terrainChart[11][5]={{1,1,1,2,1},
                             {2,1,10,10,1},
                             {1,1,2,3,1},
                             {2,1,10,10,1},
                             {1,1,1,1,1},
                             {10,10,10,10,1},
                             {1,1,1,1,1},
                             {10,10,10,10,1},
                             {1,1,1,1,1},
                             {1,1,1,1,1},
                             {10,10,10,10,10}};

    int temp=game->getTerrainMap().getElement(x,y);
    int terrainType=0;
    if (temp==1)
        terrainType=0;
    else if(temp==2)
        terrainType=1;
    else if(temp==3)
        terrainType=2;
    else if(temp>=4 && temp<=14)
        terrainType=3;
    else if(temp>=15 && temp<=24)
        terrainType=4;
    else if(temp==28)
        terrainType=5;
    else if(temp>=29 && temp<=32)
        terrainType=6;
    else if(temp==33)
        terrainType=7;
    else if(temp==34 || temp==38 || temp==43)
        terrainType=8;
    else if(temp==35 || temp==39 || temp==44)
        terrainType=9;
    else if(temp>=101 && temp<=110)
        terrainType=10;
    return terrainChart[terrainType][this->getMoveType()];
}


bool Unit::terrain_avail(int x,int y)
{
    bool res=true;
    if (x<0 || y<0 || x>=game->getTerrainMap().getSize('x') || y>=game->getTerrainMap().getSize('y') || (game->getUnitMap().getElement(x,y)!=0 && this->type!=game->getUnitMap().getElement(x,y)))


        res=false;


    return res;
}




bool compare_position(vector<int> const& a, vector<int> const& b)
{
    return a[2] < b[2];
}

void Unit::movePossib_recusif(vector<vector<int>>* l1, vector<vector<int>> l2)
{
    vector<vector<int>>& L1 = *l1;
    vector<vector<int>> l4;                       /*cette liste nous donnera les prochaines positions
                                                     *sur lesquelles il faudra appliquer la fonction récursive*/
    bool rest_MP = false;
    for (unsigned int i = 0;i < l2.size(); ++i)                 //pour tous les éléments de la sous-liste à traiter
    {
        vector<vector<unsigned int>> l3;
        l3.push_back({static_cast<unsigned int>(l2[i][0]), static_cast<unsigned int>(l2[i][1]+1) });
        l3.push_back({static_cast<unsigned int>(l2[i][0]+1), static_cast<unsigned int>(l2[i][1] )  });
        l3.push_back({static_cast<unsigned int>(l2[i][0]), static_cast<unsigned int>(l2[i][1]-1) });
        l3.push_back({static_cast<unsigned int>(l2[i][0]-1), static_cast<unsigned int>(l2[i][1]) });              //on ajoute toutes les positions autour de b à l3
        for (unsigned int j = 0;j < 4; j++)                         //pour les 4 positions autour de b:
        {
            unsigned int e = l2[i][2];
            if (terrain_avail(static_cast<unsigned int>(l3[j][0]),
                              static_cast<unsigned int>(l3[j][1])))  //si on peut se déplacer sur ce terrain
            {
                vector<unsigned int> X={l3[j][0],l3[j][1]};
                e += this->get_MPLoss(static_cast<unsigned int>(X[0]), static_cast<unsigned int>(X[1]));              //on calcul le nbe de MP restants si on va sur ce terrain
                if (e<= this->get_absMP())                   //si le nbre de points de déplacement n'est pas trop élevé
                {
                    bool inList1=false;
                    for (unsigned int k=0;k<l1->size();k++)
                    {
                        if (L1[k][0] == X[0] && L1[k][1] == X[1])       //si la position qu'on regarde est déjà dans la liste des positions possibles
                        {
                            if (L1[k][3]>e)                             //et que le chemin qu'on regarde consomme moins de MP
                            {
                                L1[k][3]=e;                                //changer le nombre de MP perdus au minimum
                            }
                            inList1=true;
                            break;//quitter la boucle
                        }
                    }

                    if (inList1 == false)
                    {
                        l1->push_back({static_cast<int>(X[0]),static_cast<int>(X[1]),static_cast<int>(e)});          //ajouter la position à la liste si elle n'y était pas
                    }

                    if (e<this->get_absMP())                  //s'il est encore possible à l'unité de se déplacer au-delà de X...
                    {
                        rest_MP = true;
                        bool inList4 = false;
                        for (unsigned int m = 0; m < l4.size(); m++)
                        {
                            if (l4[m][0] == X[0] && l4[m][1] == X[1])
                            {
                                if (l4[m][3] > e)
                                {
                                    l4[m][3] = e;
                                }
                                inList4 = true;
                                break;
                            }
                        }
                        if (inList4 == false)
                        {
                            l4.push_back({static_cast<int>(X[0]), static_cast<int>(X[1]), static_cast<int>(e)});         //... ajouter X à la liste des positions pour la prochaine fonction récursive
                        }
                    }                
                }             
            }          
        }

    }
    sort(l4.begin(), l4.end(), compare_position);
    if (rest_MP == true)
    {
        this->movePossib_recusif(l1, l4);
    }

}


vector<vector<int>> Unit::movePossib(int x,int y)
{
    vector<vector<int>> l1;
    int e=0;
    l1.push_back({x,y,e});
    movePossib_recusif(&l1,l1);
    return l1;
}

void Unit::move(unsigned int x,unsigned int y)
{
    if(canPlay)
    {
        unsigned int oldX = position[0];
        unsigned int oldY = position[1];
        Unit *unit = nullptr;
        if (PUM->getElement(x,y) == type){
            unit = game->getCursor()->getPlayer()->getUnit(x,y);
        }
        else {
            PUM->replace(oldX, oldY, x, y);
            vector<unsigned int> newposition = {x, y};
            this->setposition(newposition);
            this->resetMP();
        }
        int T = game->getTerrainMap().getElement(oldX,oldY);
        if (T>=34 && T<=36) {
            game->getBuilding(oldX,oldY)->resetLife();
        }
        else if(43 <= T && T <= 45){  // 43 <= T <= 45
            game->getPlayer(2)->getBuilding(oldX,oldY)->resetLife();
        }
        else if(38 <= T && T <= 40){
            game->getPlayer(1)->getBuilding(oldX,oldY)->resetLife();
        }
        if (unit != nullptr) {
            join_unit(unit);
        }
    }
}

void Unit::capture()
{
    if ((type==58 || type==50) && canPlay)
    {
        Map terrainMap = game->getTerrainMap();
        int build=terrainMap.getElement(position[0],position[1]);
        if (build>=34 && build<=36)
        {
            game->getBuilding(position[0],position[1])->setLife(HP,game->getPlayer(color));
        }
        else if(color==1 && build>=43 && build<=45)
        {
            game->getPlayer(2)->getBuilding(position[0],position[1])->setLife(HP,game->getPlayer(color));
        }
        else if(color==2 && build>=38 && build<=40)
        {
            game->getPlayer(1)->getBuilding(position[0],position[1])->setLife(HP,game->getPlayer(color));
        }
        canPlay = false;
    }

}

void Unit::wait(){
    canPlay = false;
}

Unit::~Unit()
{
   game->getPlayer(color)->delete_unit(this);
   PUM->setElement(0,position[0], position[1]);
}

