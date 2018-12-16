#include <iostream>
#include "game.h"
#include "city.h"
#include "factory.h"
#include "airport.h"
#include "infantery.h"
#include "inactiveai.h"
#include "pathfindai.h"

Game::Game(int gameType):terrainMap("Map1V1.txt"),
    unitMap(terrainMap.getSize('x'),
            terrainMap.getSize('y')),cursor(5,5,&unitMap,&terrainMap),
            w(&terrainMap,&unitMap,&cursor,gameType)
{
    unitMap.setWindow(&w);
    terrainMap.setWindow(&w);
    w.show();

    /*Initialisation du tableau de défense*/

    //defenseChart = initDefense(terrainMap);
    std::vector<std::vector<int>> defenseChart;
    defenseChart.resize(terrainMap.getSize('y'));
    for (unsigned int i = 0; i < terrainMap.getSize('y');i++){
        defenseChart[i].resize(terrainMap.getSize('x'));
        for (unsigned int j = 0; j < terrainMap.getSize('x');j++){
            int n = terrainMap.getElement(j,i);
            if ((n >= 4 && n <= 32)||n >= 101){
              defenseChart[i][j] = 0;
            }
            else if (n == 1 ||n == 33){
              defenseChart[i][j] = 1;
            }
            else if (n == 3){
              defenseChart[i][j] = 2;
            }
            else if (n == 2 || n == 42 || n == 47){
              defenseChart[i][j] = 4;
            }
            else {defenseChart[i][j] = 3;}
        }
    }
    this->defenseChart = defenseChart;

    neutralBuildings = {};
    vector<Building*> buildingsOS = {};     //OS = orange star
    vector<Building*> buildingsBM = {};     //BM = bleu moon

    /*ajout des batimentst*/

    for (unsigned int i = 0; i < terrainMap.getSize('y');i++){
        for (unsigned int j = 0; j < terrainMap.getSize('x');j++){
            int temp = terrainMap.getElement(j,i);
            vector<unsigned int> pos;
            pos.push_back(j);
            pos.push_back(i);
            switch(temp){
                case 34:{
                    neutralBuildings.push_back(new City(pos,this,false));
                    break;
                }
                case 35:{
                    neutralBuildings.push_back(new Factory(pos,this));
                    break;
                }
                case 36:{
                    neutralBuildings.push_back(new Airport(pos,this));
                    break;
                }
                case 38:{
                    buildingsOS.push_back(new City(pos,this,false));
                    break;
                }
                case 39:{
                    buildingsOS.push_back(new Factory(pos,this));
                    break;
                }
                case 40:{
                    buildingsOS.push_back(new Airport(pos,this));
                    break;
                }
                case 43:{
                    buildingsBM.push_back(new City(pos,this,false));
                    break;
                }
                case 44:{
                    buildingsBM.push_back(new Factory(pos,this));
                    break;
                }
                case 45:{
                    buildingsBM.push_back(new Airport(pos,this));
                    break;
                }
                case 42:{
                    buildingsOS.push_back(new City(pos,this,true));
                    break;
                }
               case 47:{
                    buildingsBM.push_back(new City(pos,this,true));
                    break;
                }
            }
        }
    }
    Player *playerOS = new Player(1,buildingsOS,&terrainMap,&unitMap);
    Player *playerBM = new Player(2,buildingsBM,&terrainMap,&unitMap);
    listPlayer = {playerOS, playerBM};
    cursor.setPlayer(playerBM,2);
    cursor.setPlayer(playerOS,1);

    cursor.getPlayer()->set_money(3000,'a');
    //création de l'unité de base de OS
    Unit* firstUnit = new infantery({15,3},1,0,this);

    firstUnit->setCanPlay(true);

    listPlayer[0]->add_unit(firstUnit);

    //IA qui joue
    if (w.getInactiveAI()){
        w.setAI(new InactiveAI(this,1));        //joue Orange Star
    }
    if (w.getPathfindAI()){
        w.setAI(new PathfindAI(this,2));        //joue Blue Moon
    }
}

void Game::delete_building(Building* building){
    unsigned int i = 0;
    while (neutralBuildings[i] != building){
        i++;
    }
    if ( i < neutralBuildings.size()){
       neutralBuildings.erase(neutralBuildings.begin()+static_cast<int>(i));
    }
    else {cout<<"Bâtiment non trouvé"<<endl;}

}
void Game::updateMap(int type,unsigned int x,unsigned int y)
{
    unitMap.setElement(type,x,y);
}

Map Game::getTerrainMap() const{
    return terrainMap;
}

Map Game::getUnitMap() const{
    return unitMap;
}

Cursor* Game::getCursor()
{
    return &cursor;
}

int Game::getDefense(unsigned int X, unsigned int Y) const{
    return defenseChart[X][Y];
}

Building* Game::getBuilding(unsigned int X,unsigned int Y)
{
    Building* build = nullptr;
    for (Building* b:neutralBuildings){
        if (b->get_X() == X && b->get_Y() == Y){
            build = b;
        }
    }
    return build;
}

Player* Game::getPlayer(int color)
{
    Player* P=nullptr;
    if (color == 1)
    {
        P=listPlayer[0];
    }
    else if(color == 2)
    {
        P=listPlayer[1];
    }
    return P;
}

std::vector<std::vector<int>>* Game::getDefenseChart(){
    return &defenseChart;
}

Map* Game::getPTM() {
    return &terrainMap;
}

Map* Game::getPUM() {
    return &unitMap;
}

void Game::updateWindow()
{
    w.updateWidget();
}

void Game::play(Player player)
{
    for (Unit *unit:player.get_listUnit())
    {
        unit->setCanPlay(true);
        unit->setHP(2,'a');
    }

    player.set_money(1000 * static_cast<int>(player.get_listBuilding().size()),'a');

    while (player.getTurn())
    {

    }
    cursor.switchPlayerState();
}

Game::~Game(){
    for (Building* b : neutralBuildings){
        delete b;
    }
    for (Building* b : listPlayer[0]->get_listBuilding()){
        delete b;
    }
    for (Building* b : listPlayer[1]->get_listBuilding()){
        delete b;
    }
    for (Unit* u : listPlayer[0]->get_listUnit()){
        delete u;
    }
    for (Unit* u : listPlayer[1]->get_listUnit()){
        delete u;
    }
    for (Player* p : listPlayer){
        delete p;
    }
}
