#ifndef NEWPATHFINDINGAI_H
#define NEWPATHFINDINGAI_H
#include "ai.h"
#include <vector>

class NewPathFindingAI : public AI
{
    Q_OBJECT
public:
    NewPathFindingAI(Game *game,int player);
    void moveAllUnit();
    void createAllUnit();
    void aiTurn();
    int partition(std::vector<double> A,std::vector<std::vector<int>> B,int left,int right);
    int randomPivot(std::vector<double> A,std::vector<std::vector<int>> B,int left,int right);
    void quickSort(std::vector<double> A,std::vector<std::vector<int>> B,int left,int right);
private:
    int hq_PosX;
    int hq_PosY;
};

#endif // NEWPATHFINDINGAI_H
