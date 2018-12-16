#ifndef AI_H
#define AI_H
#include "game.h"


class AI : public QObject
{
    Q_OBJECT
public:
    AI(Game *game,int player);
public slots:
    virtual void aiTurn();
protected:
    Game* game;
    int player;
};

#endif // AI_H
