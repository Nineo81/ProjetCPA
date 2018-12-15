#ifndef PATHFINDAI_H
#define PATHFINDAI_H
#include "ai.h"


class PathfindAI:public AI
{
    Q_OBJECT
public:
    PathfindAI(Game *game,int player);
public slots:
    void play();
};

#endif // PATHFINDAI_H
