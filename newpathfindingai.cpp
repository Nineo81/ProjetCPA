#include "newpathfindingai.h"
#include "unit.h"
#include "building.h"

NewPathFindingAI::NewPathFindingAI(Game *game,int player) : game(game),player(player)
{
    //Trouver position du QG de l'enemi
    for(int y=0 ; y<this->game->getTerrainMap().getSize('y') ; y++)
    {
        for(int x=0 ; x<this->game->getTerrainMap().getSize('x') ; x++)
        {
            if(player == 1 && this->game->getTerrainMap().getElement(x,y) == 47)
            {
                hq_PosX=x;
                hq_PosY=y;
            }
            else if(player == 2 && this->game->getTerrainMap().getElement(x,y) == 42)
            {
                hq_PosX=x;
                hq_PosY=y;
            }
        }
    }
}

void NewPathFindingAI::moveAllUnit()
{
    //Verifie qu'il a des unite
    if(this->game->getPlayer(player)->get_listUnit().empty())
    {
        return;
    }
    for(Unit* u : this->game->getPlayer(player)->get_listUnit())
    {
        //Verifie que l'on est pas deja sur le QG
        if(u->get_X() == hq_PosX && u->get_Y() == hq_PosY)
        {
            u->capture();
            return;
        }
        //Trouver toute les positions possibles pour l'unit
        movePossible = u->movePossib(u->get_X(),u->get_Y());
        dist = {};
        //Calcul de la distance entre les positions possible et le QG
        for(std::vector<int> pos : movePossible)
        {
            dist.push_back(sqrt(pow(hq_PosX-pos[0],2)+pow(hq_PosY-pos[1],2)));
        }

        //Trouver la distance la plus faible
        quickSort(0,dist.size()-1);
        //déplacer l'unit
        for (int i = 0;i<movePossible.size();i++){
            if (game->getPUM()->getElement(movePossible[i][0],movePossible[i][1]) == 0){
                u->move(movePossible[i][0],movePossible[i][1]);
                if(movePossible[0][0] == hq_PosX && movePossible[0][1] == hq_PosY)
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

void NewPathFindingAI::createAllUnit()
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

void NewPathFindingAI::aiTurn()
{
    moveAllUnit();
    createAllUnit();
    if(this->game->getWindow()->hqControl())
    {
        this->game->closeGame();
    }
    this->game->getCursor()->switchPlayerState();
}

int NewPathFindingAI::partition(int left,int right)
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
int NewPathFindingAI::randomPivot(int left,int right)
{
    int pivot,n;
    n = rand();

    pivot = left + n%(right-left+1);

    std::swap(dist[right],dist[pivot]);
    std::swap(movePossible[right],movePossible[pivot]);

    return partition(left,right);
}

void NewPathFindingAI::quickSort(int left,int right)
{
    int i;
    if(left < right)
    {
        i = randomPivot(left,right);
        quickSort(left,i-1);
        quickSort(i+1,right);
    }
}
