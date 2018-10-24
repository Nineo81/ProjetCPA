#ifndef MAP_H
#define MAP_H
#include <vector>
#include "gameobject.h"

class Map
{
public:
    Map();

private:
    std::vector<std::vector<GameObject>> map;
};

#endif // MAP_H
