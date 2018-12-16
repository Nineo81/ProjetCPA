#ifndef PATHFINDAI_H
#define PATHFINDAI_H
#include "ai.h"


class PathfindAI:public AI
{
    Q_OBJECT
public:
    PathfindAI(Game *game,int player);
    void findAllPathes(Unit * unit, int x, int y, vector<vector<int>> path);
    vector<vector<int>> findPath(vector<vector<vector<int> > > allPathes);
    bool isIn(vector<int> a,vector<vector<int>> b);
    int dToTarget(int x, int y);
public slots:
    void play();
private:
    unsigned int xTarget = 16;
    unsigned int yTarget = 2;
    vector<vector<vector<int>>> allPath;
    vector<vector<int>> bestPath;
    int min = 20;
    int bestCost = 40;
};

#endif // PATHFINDAI_H
