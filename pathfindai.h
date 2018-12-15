#ifndef PATHFINDAI_H
#define PATHFINDAI_H
#include "ai.h"


class PathfindAI:public AI
{
    Q_OBJECT
public:
    PathfindAI(Game *game,int player);
    vector<vector<vector<int>>> findAllPathes(Unit * unit, unsigned int x, unsigned int y, vector<vector<int>> path);
    vector<vector<int>> findPath(vector<vector<vector<int> > > allPathes);
    bool isIn(vector<int> a,vector<vector<int>> b);
public slots:
    void play();
private:
    unsigned int xTarget = 16;
    unsigned int yTarget = 2;
    vector<vector<int>> tried;
    vector<vector<vector<int>>> allPath;
};

#endif // PATHFINDAI_H
