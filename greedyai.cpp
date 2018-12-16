#include "greedyai.h"

GreedyAI::GreedyAI(Game* game, int player):AI(game,player)
{
    this->player=player;
    this->game=game;
}

void GreedyAI::moveAllUnit()
{
    //Verifie qu'il a des unite
    if(this->game->getPlayer(player)->get_listUnit().empty())
    {
        return;
    }
    for(Unit* u : this->game->getPlayer(player)->get_listUnit())
    {
        vector<int> b = findBuild(u->get_X(),u->get_Y());
        //Verifie que l'on est pas deja sur une ville
        if(u->get_X() == b[0] && u->get_Y() == b[1])
        {
            u->capture();
            return;
        }
        //Trouver toute les positions possibles pour l'unit
        movePossible = u->movePossib(u->get_X(),u->get_Y());
        dist = {};
        //Calcul de la distance entre les positions possible la ville
        for(std::vector<int> pos : movePossible)
        {
            dist.push_back(sqrt(pow(b[0]-pos[0],2)+pow(b[1]-pos[1],2)));
        }

        //Trouver la distance la plus faible
        quickSort(0,dist.size()-1);
        //déplacer l'unit
        for (int i = 0;i<movePossible.size();i++){
            if (game->getPUM()->getElement(movePossible[i][0],movePossible[i][1]) == 0){
                u->move(movePossible[i][0],movePossible[i][1]);

                if(movePossible[0][0] == b[0] && movePossible[0][1] == b[1])
                {
                    u->capture();
                }
                else
                {
                    u->wait();
                }
                break;
            }
        }
    }
}

void GreedyAI::buildsUpdate(){
    builds = {};
    for(int y=0 ; y<this->game->getTerrainMap().getSize('y') ; y++)
    {
        for(int x=0 ; x<this->game->getTerrainMap().getSize('x') ; x++)
        {
            if(player == 1 && 43 <= this->game->getTerrainMap().getElement(x,y) && this->game->getTerrainMap().getElement(x,y) <= 47)
            {
                builds.push_back({x,y});
            }
            else if(player == 2 && (38 <= this->game->getTerrainMap().getElement(x,y) && this->game->getTerrainMap().getElement(x,y) <= 42))
            {
                builds.push_back({x,y});
            }
            if(34 <= this->game->getTerrainMap().getElement(x,y) && this->game->getTerrainMap().getElement(x,y) <= 36)
            {
                builds.push_back({x,y});
            }
        }
    }
}

vector<int> GreedyAI::findBuild(int x,int y)
{
    buildsUpdate();
    vector<int> b = builds[0];
    double d = sqrt(pow(b[0]-x,2)+pow(b[1]-y,2));
    for (vector<int> bat : builds){
        if ( sqrt(pow(bat[0]-x,2)+pow(bat[1]-y,2) < d)){
             b = bat;
             d = sqrt(pow(bat[0]-x,2)+pow(bat[1]-y,2));
        }
    }
    return b;
}

void GreedyAI::createAllUnit()
{
    if(this->game->getPlayer(player)->get_listBuilding().empty())
    {
        return;
    }
    for(Building* b : this->game->getPlayer(player)->get_listBuilding())
    {
        if(b->getType() == 35 && this->game->getUnitMap().getElement(b->get_X(),b->get_Y()) == 0)
        {
            if(this->game->getPlayer(player)->get_money()>1000)
            {
                b->createUnit(1);
            }
        }
    }
}

void GreedyAI::aiTurn()
{
    moveAllUnit();
    createAllUnit();
    this->game->getCursor()->switchPlayerState();
}

int GreedyAI::partition(int left,int right)
{
    double x = dist[right];
    int i = left;
    for(int j=left;j<right;j++)
    {
        if(dist[j] <= x)
        {
            std::swap(dist[i],dist[j]);
            std::swap(movePossible[i],movePossible[j]);
            i++;
        }
    }
    std::swap(dist[i],dist[right]);
    std::swap(movePossible[i],movePossible[right]);
    return i;
}

//Selection aleatoire du pivot
int GreedyAI::randomPivot(int left,int right)
{
    int pivot,n;
    n = rand();

    pivot = left + n%(right-left+1);

    std::swap(dist[right],dist[pivot]);
    std::swap(movePossible[right],movePossible[pivot]);

    return partition(left,right);
}

void GreedyAI::quickSort(int left,int right)
{
    int i;
    if(left < right)
    {
        i = randomPivot(left,right);
        quickSort(left,i-1);
        quickSort(i+1,right);
    }
}
