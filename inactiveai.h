#ifndef INACTIVEAI_H
#define INACTIVEAI_H
#include "ai.h"


class InactiveAI: public AI
{
    Q_OBJECT
public:
    InactiveAI(Game *game,int player);
public slots:
    void play();
private :
    Game *game;
    int player;
};

#endif // INACTIVEAI_H
