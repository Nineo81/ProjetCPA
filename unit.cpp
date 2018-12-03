#include "unit.h"
#include <string>
#include <iostream>
//#include<algorithm>
#include "game.h"


using namespace std;


Unit::Unit(int pos[2], int color, int round, vector<vector<int>> *PDC, Map *PTM, Map *PUM) : GameObject(pos)
{
    this->color=color;
    this->round=round;
    this->HP=10;
    this->PDC=PDC;
    this->PTM=PTM;
    this->PUM=PUM;
    Map unitMap=*PUM;
    if (color==1)
        unitMap.setElement(this->type,position[0],position[1]);
    else
        unitMap.setElement(this->type+10,position[0],position[1]);      //il faudra peut être changer le +10
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

Map Unit::getUnitMap() const
{
    return *PUM;
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

int Unit::get_absMP() const
{
    return this->absMP;
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

bool Unit::can_attack(Unit defender)
{
    int B=this->find_B(defender);
    if (B!=0)
        return true;
    else
        return false;
}

int Unit::get_D_TR() const
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
                             {10,10,10,10,10}};
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


bool Unit::terrain_avail(int x,int y)
{
    Map terrainMap=this->getTerrainMap();
    Map unitMap=this->getUnitMap();
    bool res=true;
    if (x<0 || y<0 || x>=(terrainMap.getSize('m')+1) || y>=(terrainMap.getSize('p')-1) || this->type!=unitMap.getElement(x,y))
        res=false;
    return res;
}


/*vector<vector<int>> Unit::fusion(vector<vector<int>> l4, vector<vector<int>> vLeft, vector<vector<int>> vRight)
{
    int iL=0;
    int iR=0;
    vLeft.push_back({0,0,100});
    vRight.push_back({0,0,100});
    for (int i=0;i<l4.size()-1;i++)
    {
        if (vLeft[iL][2]<vRight[iR][2])
        {
            l4[i]=vLeft[iL];
            iL++;
        }
        else
        {
            l4[i]=vRight[iR];
            iR++;
        }
    }
    if
    return l4;
}

void Unit::mergesort_ListPos(vector<vector<int>> l4,int left,int mid, int right)
{
    int nl=mid-left; int nr=right-mid+1;
    vector<vector<int>> vLeft;
    vector<vector<int>> vRight;
    for (int i=left;i<mid-1;i++)
    {
        vLeft.push_back(l4[i]);
    }
    for(int i=mid;i<right;i++)
    {
        vRight.push_back(l4[i]);
    }
    if (vLeft.size()!=1)

}*/











void Unit::movePossib_recusif(vector<vector<int>> l1,vector<vector<int>> l2)
{
    vector<vector<int>> l4;                       /*cette liste nous donnera les prochaines positions
                                                              *sur lesquelles il faudra appliquer la fonction récursive*/
    bool rest_MP=false;
    for (int i=0;i<l2.size();++i)                 //pour tous les éléments de la sous-liste à traiter
    {
        vector<vector<int>> l3;
        l3.push_back({l2[i][0],   l2[i][1]+1 });
        l3.push_back({l2[i][0]+1, l2[i][1]   });
        l3.push_back({l2[i][0],   l2[i][1]-1 });
        l3.push_back({l2[i][0]-1, l2[i][1]   });              //on ajoute toutes les positions autour de b à l3
        for (int j=0;j<3;j++)                         //pour les 4 positions autour de b:
        {
            int e=l2[i][2];
            if (terrain_avail(l3[j][0],l3[j][1])==true)  //si on peut se déplacer sur ce terrain
            {
                vector<int> X={l3[j][0],l3[j][1]};
                e-=this->get_MPLoss(X[0],X[1]);              //on calcul le nbe de MP restants si on va sur ce terrain
                if (e<= this->get_absMP())                   //si le nbre de points de déplacement n'est pas trop élevé
                {
                    int k=0;
                    bool inList1=false;
                    while (k<l1.size() || inList1==false)
                    {
                        if (l1[k][0]==X[0] && l1[k][1]==X[1])       //si la position qu'on regarde est déjà dans la liste des positions possibles
                        {
                            if (l1[k][3]>e)                             //et que le chemin qu'on regarde consomme moins de MP
                            {
                                l1[k][3]=e;                                //changer le nombre de MP perdus au minimum
                            }
                            inList1=true;                                //quitter la boucle
                        }
                        k++;
                    }
                    if (inList1==false)
                    {
                        l1.push_back({X[0],X[1],e});          //ajouter la position à la liste si elle n'y était pas
                    }
                    if (e<this->get_absMP())                  //s'il est encore possible à l'unité de se déplacer au-delà de X...
                    {
                        rest_MP=true;
                        int m=0;
                        bool inList4=false;
                        while (m<l4.size() || inList4==false)
                        {
                            if (l4[m][0]==X[0] && l4[m][1]==X[1])
                            {
                                if (l4[m][3]>e)
                                {
                                    l4[m][3]=e;
                                }
                                inList4=true;
                            }
                            m++;
                        }
                        if (inList4==false)
                        {
                            l4.push_back({X[0],X[1],e});         //... ajouter X à la liste des positions pour la prochaine fonction récursive
                        }

                    }
                }
            }
        }

    }
    //IL FAUT TRIER L4!!!!
    if (rest_MP==true)
    {
        this->movePossib_recusif(l1,l4);
    }
}

vector<vector<int>> Unit::movePossib(int x,int y)
{
    vector<vector<int>> l1;
    int e=0;
    l1.push_back({x,y,e});
    this->movePossib_recusif(l1,l1);
    return l1;
}


void Unit::move(int x, int y)
{
    Map unitMap=this->getUnitMap();
    int oldX=this->get_X();
    int oldY=this->get_Y();
    unitMap.replace(oldX,oldY,x,y);
    int newposition[2]={x,y};
    this->setposition(newposition);
    this->resetMP();
}

