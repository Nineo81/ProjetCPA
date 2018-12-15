#include "pathfindai.h"

PathfindAI::PathfindAI(Game* game,int player):AI(game,player)       //donner une couleur ou un *player??
{
    for (Unit * unit : game->getPlayer(player)->get_listUnit()){
        tried = {};
        allPath = {};
        unit->setBestPath(findPath(findAllPathes(unit,unit->get_X(), unit->get_Y(), {})));
    }
}

void PathfindAI::play(){
    cout<<"C'est mon tour?"<<endl;
    if (game->getCursor()->getPlayerState() == player){
        cout<<"Tour de l'IA"<<endl;
        for (Unit * unit : game->getPlayer(player)->get_listUnit()){
            cout<<"Unit 1"<<endl;
            unsigned int nextX = unit->getBestPath()[unit->getBestPath().size()-1][0];
            unsigned int nextY = unit->getBestPath()[unit->getBestPath().size()-1][1];
            cout<<"Unit 2"<<endl;
            if (unit->get_X() != xTarget && unit->get_Y() != yTarget
                    && game->getPUM()->getElement(nextX,nextY) == 0){
                unit->move(nextX,nextY);
                unit->getPBP()->pop_back();
            }
            else if (unit->get_X() == xTarget && unit->get_Y() == yTarget){
                unit->capture();
            }
        }
        for (Building* f : game->getPlayer(player)->get_listBuilding()){
            if (f->getType() == 35 && game->getPUM()->getElement(f->get_X(),f->get_Y()) == 0
                    && game->getPlayer(player)->get_money() >= 1000){
                f->createUnit(1);
                cout<<"unité crée"<<endl;
            }
        }
        for (Unit * unit : game->getPlayer(player)->get_listUnit()){
            if (unit->getBestPath().size() == 0){
                cout<<"Unit1"<<endl;
                allPath = {};
                tried = {};
                //unit->setBestPath(findPath(findAllPathes(unit,unit->get_X(), unit->get_Y(), {})));
                vector<vector<vector<int>>> essai = findAllPathes(unit,unit->get_X(), unit->get_Y(), {});
                cout<<"Unit, path done"<<endl;
            }
        }
        game->getCursor()->switchPlayerState();
        cout<<"Ton tour!"<<endl;
    }
}

vector<vector<vector<int>>> PathfindAI::findAllPathes(Unit *unit, unsigned int x, unsigned int y, vector<vector<int>> path){
    vector<vector<int>> movPoss = unit->movePossib(x,y);
    cout<<"movPoss possible!"<<endl;
    for(vector<int> posPoss : unit->movePossib(x,y)){
        if (!isIn(posPoss,tried)){
            tried.push_back(posPoss);    //se renouvelle quand on réappelle la fct
            path.push_back(posPoss);
            if  (posPoss[0] == xTarget && posPoss[1] == yTarget ){
                allPath.push_back(path);
            }
            else {
                findAllPathes(unit, posPoss[0], posPoss[1], path);
            }
        }
    }
    return allPath;
}

vector<vector<int>> PathfindAI::findPath(vector<vector<vector<int>>> allPathes){
    vector<vector<int>> bestPath = allPathes[0];
    for (vector<vector<int>> path : allPathes){
        if ( path.size() < bestPath.size()){
            bestPath = path;
        }
    }
    vector<vector<int>> truePath;
    for (int i = 0 ; i < bestPath.size() ; i++){
        truePath[i] = bestPath[bestPath.size() - 1 - i];
    }
    return truePath;
}

bool PathfindAI::isIn(vector<int> a, vector<vector<int> > b){
    bool isin = false;
    for (vector<int> i : b){
        if (i == a){ isin = true;}
    }
    return isin;
}
