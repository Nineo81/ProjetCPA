#include <iostream>
#include "game.h"
#include "city.h"
#include "factory.h"
#include "airport.h"

Game::Game():cursor(5,5),terrainMap("Map1V1.txt"),
            unitMap(terrainMap.getSize('m'),
            terrainMap.getSize('p')),w(&terrainMap,&unitMap,&cursor)
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
    this->defenseChart = defenseChart;

    neutralBuildings = {};
    vector<Building*> buildingsOS = {};     //OS = orange star
    vector<Building*> buildingsBM = {};     //BM = bleu moon

    /*ajout des batimentst*/

    for (unsigned int i = 0; i<terrainMap.getSize('m');i++){
        for (unsigned int j = 0; j<terrainMap.getSize('p');j++){
            int temp =terrainMap.getElement(i,j);
            int pos[2];
            pos[0] = i;
            pos[1] = j;
            Building *building = nullptr;
            switch(temp){
                case 34:{
                    building = new City(pos);
                    neutralBuildings.push_back(*building);
                    break;
                }
                case 35:{
                    building = new Factory(pos, &defenseChart);
                    neutralBuildings.push_back(*building);
                    break;
                }
                case 36:{
                    building = new Airport(pos,&defenseChart);
                    neutralBuildings.push_back(*building);
                    break;
                }
                case 38:{
                    building = new City(pos);
                    buildingsOS.push_back(building);
                    break;
                }
                case 39:{
                    building = new Factory(pos,&defenseChart);
                    buildingsOS.push_back(building);
                    break;
                }
                case 40:{
                    building = new Airport(pos,&defenseChart);
                    buildingsOS.push_back(building);
                    break;
                }
                case 42:{
                    building = new City(pos);
                    buildingsBM.push_back(building);
                    break;
                }
                case 43:{
                    building = new Factory(pos,&defenseChart);
                    buildingsBM.push_back(building);
                    break;
                }
                case 44:{
                    building = new Airport(pos,&defenseChart);
                    buildingsBM.push_back(building);
                    break;
                }
            }
        }
    }
    Player *playerOS = new Player(1,buildingsOS,&terrainMap,&unitMap);
    Player *playerBM = new Player(2,buildingsBM,&terrainMap,&unitMap);
    listPlayer = {*playerOS, *playerBM};
}

Map Game::getTerrainMap() const{
    return terrainMap;
}

Map Game::getUnitMap() const{
    return unitMap;
}

int Game::getDefense(unsigned int X, unsigned int Y) const{
    return defenseChart[X][Y];
}

void Game::updateWindow()
{
    w.updateWidget();
}

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
