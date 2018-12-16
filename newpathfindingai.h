#ifndef NEWPATHFINDINGAI_H
#define NEWPATHFINDINGAI_H
#include "ai.h"
#include <vector>
#include "game.h"

class NewPathFindingAI: public AI
{
public:
    NewPathFindingAI(Game *game,int player);
    void moveAllUnit();
    void createAllUnit();
    void aiTurn();
    int partition(int left,int right);
    int randomPivot(int left,int right);
    void quickSort(int left,int right);
private:
    int hq_PosX;
    int hq_PosY;
    std::vector<std::vector<int>> movePossible;
    std::vector<double> dist;
};

#endif // NEWPATHFINDINGAI_H
