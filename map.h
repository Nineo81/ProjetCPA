#ifndef MAP_H
#define MAP_H
#include <vector>
#include <string>

class Map
{
public:
    Map();
    void ReadFile(std::string fileName);

private:
    std::vector<std::vector<int>> map;
};

#endif // MAP_H
