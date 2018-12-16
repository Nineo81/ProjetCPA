#ifndef GREEDYAI_H
#define GREEDYAI_H
#include "ai.h"


class GreedyAI:public AI
{
    Q_OBJECT
public:
    GreedyAI(Game* game, int player);
    void moveAllUnit();
    void createAllUnit();
    void turn();
    int partition(int left,int right);
    int randomPivot(int left,int right);
    void quickSort(int left,int right);
    vector<int> findBuild(int x, int y);
    void buildsUpdate();
private:
    vector<vector<int>> builds;
    std::vector<std::vector<int>> movePossible;
    std::vector<double> dist;
};

#endif // GREEDYAI_H
