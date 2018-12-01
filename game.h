#ifndef GAME_H
#define GAME_H
#include <string>
#include "map.h"
#include "mainwindow.h"
#include <vector>
#include "building.h"
#include "player.h"
#include "cursor.h"

class Game
{
private:
   Map terrainMap;
   Map unitMap;
   Cursor cursor;
   MainWindow w;
   std::vector<std::vector<int>> defenseChart;
   std::vector<Building*> neutralBuildings;
   std::vector<Player> listPlayer;
public:
    Game();
   // ~Game();        //allocation dynamique pour les joueurs, normalement il faut un destructeur?
    Map getTerrainMap() const;
    Map getUnitMap() const;
    Cursor* getCursor();
    int getDefense(unsigned int X, unsigned int Y) const;
    void start();
    std::vector<std::vector<int>> initDefense(Map terrainMap);
    void updateWindow();
};

#endif // GAME_H
