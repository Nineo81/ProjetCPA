#ifndef CURSOR_H
#define CURSOR_H
#include "map.h"
#include <QRect>
#include <vector>
#include "player.h"
using namespace std;

class Cursor : public QRect
{
public:
    Cursor(int posX,int posY,Map* unitMap,Map* terrainMap);
    void move(int up,int left,int down,int right);
    void moveAlt(int up,int left,int down,int right);
    int getPosX();
    int getPosY();
    int getRealX();
    int getRealY();
    Player* getPlayer();
    void setPlayer(Player* player,int type);
    bool unitOfPlayer();
    bool opponnentUnit();
    int buildOfPlayer();
    bool onABuilding();
    void switchPlayerState();
    void setSizePicture(int sizePicture);
    void updateMovements(vector<vector<int>> movements);
    int getPlayerState() const;
private:
    vector<vector<int>> movements;
    int sizePicture;
    int posX;
    int posY;
    int playerState;
    Map* unitMap;
    Map* terrainMap;
    Player* playerOS;
    Player* playerBM;
};

#endif // CURSOR_H
