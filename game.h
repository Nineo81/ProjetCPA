#ifndef GAME_H
#define GAME_H
#include <string>
#include <QWidget>
#include "map.h"
#include "mainwindow.h"
#include <vector>
#include "building.h"
#include "player.h"
#include "cursor.h"

class NewPathFindingAI;
class Game : public QWidget
{
    Q_OBJECT
private:
   NewPathFindingAI* ai;
   Map terrainMap;
   Map unitMap;
   Cursor cursor;
   MainWindow w;
   std::vector<std::vector<int>> defenseChart;
   std::vector<Building*> neutralBuildings;
   std::vector<Player*> listPlayer;
public:
    Game(int gameType);
    ~Game();        //allocation dynamique pour les joueurs, normalement il faut un destructeur?
    Map getTerrainMap() const;
    Map* getPTM();
    Map* getPUM();
    Map getUnitMap() const;
    void updateMap(int type,unsigned int x,unsigned int y);
    Cursor* getCursor();
    Player* getPlayer(int color);
    int getDefense(unsigned int X, unsigned int Y) const;
    std::vector<std::vector<int>>* getDefenseChart();
    void start();
    std::vector<std::vector<int>> initDefense(Map terrainMap);
    void updateWindow();
    Building* getBuilding(unsigned int x,unsigned int y);
    void play(Player player);
    void otherTurn();
    void delete_building(Building *building);
public slots:
    void closeGame();
    void aiPlay();
};

#endif // GAME_H
