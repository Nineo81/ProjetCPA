#ifndef CURSOR_H
#define CURSOR_H
#include "map.h"
#include <QRect>
#include "player.h"


class Cursor : public QRect
{
public:
    Cursor(int posX,int posY,Map* unitMap,Map* terrainMap);
    void move(int up,int left,int down,int right);
    int getPosX();
    int getPosY();
    int getRealX();
    int getRealY();
    Player* getPlayer();
    void setPlayer(Player* player,int type);
    bool unitOfPlayer();
    int buildOfPlayer();
    void switchPlayerState();
    void setSizePicture(int sizePicture);
private:
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
