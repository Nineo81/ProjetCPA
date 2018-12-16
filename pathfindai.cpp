#include "pathfindai.h"

PathfindAI::PathfindAI(Game* game,int player):AI(game,player)       //donner une couleur ou un *player??
{
    for (Unit * unit : game->getPlayer(player)->get_listUnit()){
        allPath = {};
        findAllPathes(unit,unit->get_X(), unit->get_Y(), {});
        unit->setBestPath(bestPath);
    }
}

int PathfindAI::dToTarget(int x,int y){
    return abs(x-xTarget) + abs(y-yTarget);
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
                findAllPathes(unit,static_cast<int>(unit->get_X()), static_cast<int>(unit->get_Y()), {});
                cout<<"Imprime le!"<<endl;
                for ( vector<int> p : bestPath){
                    cout<<p[0]<<" "<<p[1]<<endl;
                }
                unit->setBestPath(bestPath);
                cout<<"Unit, path done"<<endl;
            }
        }
        game->getCursor()->switchPlayerState();
        cout<<"Ton tour!"<<endl;
    }
}

void PathfindAI::findAllPathes(Unit *unit,int x, int y, vector<vector<int>> path){
    vector<vector<int>> adjPos;
    if (x>0){adjPos.push_back({x-1,y});}
    if (y<game->getPTM()->getSize('y')){adjPos.push_back({x,y+1});}
    else if (y>0){adjPos.push_back({x,y-1});}
    else if (x<game->getPTM()->getSize('x')){adjPos.push_back({x+1,y});}
    vector<int> min = adjPos[0];
    for (vector<int> p : adjPos){
        if (dToTarget(p[0],p[1]) < dToTarget(min[0],min[1])){
            min = p;
        }
    }
    path.push_back(min);
    if (dToTarget(min[0],min[1])){
        bestPath = path;
        return;
    }
    findAllPathes(unit,min[0],min[1],path);
}

/*void PathfindAI::findAllPathes(Unit *unit,int x, int y, vector<vector<int>> path, int cost){
    vector<vector<int>> adjPos;
    if (x>0){adjPos.push_back({x-1,y});}
    if (y<game->getPTM()->getSize('y')){adjPos.push_back({x,y+1});}
    if (y>0){adjPos.push_back({x,y-1});}
    if (x<game->getPTM()->getSize('x')){adjPos.push_back({x+1,y});}

    if (path.size() > 100 || dToTarget(x,y) == 0){
        if ( dToTarget(x,y) == 0 && cost < bestCost){
            cout<<"(dToTarget(x,y) == 0)"<<endl;
            bestCost = cost;
            bestPath = path;
            min = path.size();
        }
    }
    else {
        cout<<"else"<<endl;
        for ( vector<int> pos : adjPos){
            cout<<pos[0]<<" "<<pos[1]<<endl;
            if (!isIn(pos,path) && cost<bestCost){
                path.push_back(pos);
                cost += unit->get_MPLoss(pos[0],pos[1]);
                findAllPathes(unit, pos[0], pos[1], path, cost);
                path.pop_back();
            }
        }
    }
}
*/
/*vector<vector<int>> PathfindAI::findAllPathes(Unit *unit, unsigned int x, unsigned int y, vector<vector<int>> path){
    if (path.size() !=0 && dToTarget(x,y) == 0 ){
        if (path.size() < min){
            bestPath = path;
            min = path.size();
        }
    }
    else {
        vector<vector<int>> movPoss = unit->movePossib(x,y);
        cout<<"move possible"<<endl;
        for (vector<int> posPoss : movPoss){
            cout<<"position"<<endl;
            if (!isIn(posPoss,path) && dToTarget(posPoss[0],posPoss[1]) < dToTarget(x,y) ){
                path.push_back(posPoss);
                findAllPathes(unit,posPoss[0],posPoss[1],path);
            }
        }
    }
    return path;
}*/

/*vector<vector<vector<int>>> PathfindAI::findAllPathes(Unit *unit, unsigned int x, unsigned int y, vector<vector<int>> path,vector<vector<int>> tried){
    vector<vector<int>> movPoss = unit->movePossib(x,y);
    int min = 8;
    for(vector<int> posPoss : unit->movePossib(x,y)){
        if (!isIn(posPoss,tried)){
            tried.push_back(posPoss);    //se renouvelle quand on réappelle la fct
            path.push_back(posPoss);
            if  (posPoss[0] == xTarget && posPoss[1] == yTarget ){
                allPath.push_back(path);
                if (path.size() < min){
                    min = path.size();
                }
            }
            else if (path.size() >= min){
                break;
            }
            else {
                findAllPathes(unit, posPoss[0], posPoss[1], path, tried);
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
        cout<<i<<endl;
        truePath[i] = bestPath[bestPath.size() - 1 - i];
    }
    return truePath;
}*/

bool PathfindAI::isIn(vector<int> a, vector<vector<int> > b){
    bool isin = false;
    for (vector<int> i : b){
        if (i == a){ isin = true;}
    }
    return isin;
}
