#ifndef MAP_H
#define MAP_H
#include <vector>
#include <string>

class Map
{
public:
    Map(unsigned int sizeX,unsigned int sizeY);
    Map(const char* fileName);
    void readFile(const char* fileName);

    unsigned int getSize(char a);

    int getElement(unsigned int posX, unsigned int posY);

    void setElement(int element, unsigned int posX, unsigned int posY);

private:
    std::vector<std::vector<int>> map;
};

#endif // MAP_H
