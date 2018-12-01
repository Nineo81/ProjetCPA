#include <iostream>
#include "game.h"
#include "city.h"
#include "factory.h"
#include "airport.h"

Game::Game():terrainMap("Map1V1.txt"),
            unitMap(terrainMap.getSize('m'),
            terrainMap.getSize('p')),cursor(5,5,&terrainMap,&unitMap),
            w(&terrainMap,&unitMap,&cursor)
{
    unitMap.setWindow(w.getWidget());
    w.show();

    /*Initialisation du tableau de défense
    La fonction ne marche pas pour l'instant ("undifined reference to[]")
    donc je laisse comme ça pour l'instant, je reviendrais dessus*/

    //defenseChart = initDefense(terrainMap);
    std::vector<std::vector<int>> defenseChart;
    defenseChart.resize(terrainMap.getSize('m'));
    for (unsigned int i = 0; i<terrainMap.getSize('m');i++){
        defenseChart[i].resize(terrainMap.getSize('p'));
        for (unsigned int j = 0; j<terrainMap.getSize('p');j++){
            int n =terrainMap.getElement(i,j);
            if ((n >= 4 && n <= 32)||n >= 101){
              defenseChart[i][j] = 0;
            }
            else if (n == 1 ||n == 33){
              defenseChart[i][j] = 1;
            }
            else if (n == 3){
              defenseChart[i][j] = 2;
            }
            else if (n == 2){
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

    for (unsigned int i = 0; i<terrainMap.getSize('m');i++){
        for (unsigned int j = 0; j<terrainMap.getSize('p');j++){
            int temp =terrainMap.getElement(i,j);
            int pos[2];
            pos[0] = j+1;
            pos[1] = i+1;
            switch(temp){
                case 34:{
                    neutralBuildings.push_back(new City(pos));
                    break;
                }
                case 35:{
                    neutralBuildings.push_back(new Factory(pos, &this->defenseChart,&terrainMap,&unitMap));
                    break;
                }
                case 36:{
                    neutralBuildings.push_back(new Airport(pos,&this->defenseChart,&terrainMap,&unitMap));
                    break;
                }
                case 38:{
                    buildingsOS.push_back(new City(pos));
                    break;
                }
                case 39:{
                    buildingsOS.push_back(new Factory(pos,&this->defenseChart,&terrainMap,&unitMap));
                    break;
                }
                case 40:{
                    buildingsOS.push_back(new Airport(pos,&this->defenseChart,&terrainMap,&unitMap));
                    break;
                }
                case 42:{
                    buildingsBM.push_back(new City(pos));
                    break;
                }
                case 43:{
                    buildingsBM.push_back(new Factory(pos,&this->defenseChart,&terrainMap,&unitMap));
                    break;
                }
                case 44:{
                    buildingsBM.push_back(new Airport(pos,&this->defenseChart,&terrainMap,&unitMap));
                    break;
                }
            }
        }
    }
    Player *playerOS = new Player(1,buildingsOS,&terrainMap,&unitMap);
    Player *playerBM = new Player(2,buildingsBM,&terrainMap,&unitMap);
    listPlayer = {*playerOS, *playerBM};
    cursor.setPlayer(playerBM,2);
    cursor.setPlayer(playerOS,1);
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

void Game::updateWindow()
{
    w.updateWidget();
}

/*Game::~Game(){
    for (Building* b : neutralBuildings){
        delete b;
    }
    for (Building* b : listPlayer[0].get_listBuilding()){
        delete b;
    }
    for (Building* b : listPlayer[1].get_listBuilding()){
        delete b;
    }
    for (Unit* u : listPlayer[0].get_listUnit()){
        delete u;
    }
    for (Unit* u : listPlayer[1].get_listUnit()){
        delete u;
    }
    for (Player p : listPlayer){
        delete &p;
    }
    delete this;
}*/

/*std::vector<std::vector<int>> initDefense(Map terrainMap){
    std::vector<std::vector<int>> defenseChart;
    defenseChart.resize(terrainMap.getSize('m'));
    for (unsigned int i = 0; i<terrainMap.getSize('m');i++){
        defenseChart[i].resize(terrainMap.getSize('p'));
    }
    for (unsigned int i = 0; i<terrainMap.getSize('m');i++){
        for (unsigned int j = 0; j<terrainMap.getSize('p');j++){
            int temp =terrainMap.getElement(i,j);
            if (temp == 4 || temp == 5 ||temp == 6 ||temp == 7 ||temp == 8 ||temp == 9 ||
                temp == 10 ||temp == 11 ||temp == 12 ||temp == 13 ||temp == 14 ||temp == 15 ||
                temp == 16 ||temp == 17 ||temp == 18 ||temp == 19 ||temp == 20 ||temp == 21 ||
                temp == 22 ||temp == 23 ||temp == 24 ||temp == 25 ||temp == 26 ||temp == 27 ||
                temp == 28 ||temp == 29 ||temp == 30 ||temp == 31 ||temp == 32 ||temp == 101 ||
                temp == 102 ||temp == 103 ||temp == 104 ||temp == 105 ||temp == 106 ||temp == 107 ||
                temp == 108 ||temp == 109 ||temp == 110){
              defenseChart[i][j] = 0;
            }
            else if (temp == 1 ||temp == 33){
              defenseChart[i][j] = 1;
            }
            else if (temp == 3){
              defenseChart[i][j] = 2;
            }
            else if (temp == 2){
              defenseChart[i][j] = 4;
            }
            else {defenseChart[i][j] = 3;}
        }
    }
    return defenseChart;
}
*/
