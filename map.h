#ifndef MAP_H
#define MAP_H
#include <vector>
#include <string>

class MainWindow;
class Map
{
public:
    Map(unsigned int sizeX,unsigned int sizeY);
    Map(const char* fileName);
    void readFile(const char* fileName);

    unsigned int getSize(char a);

    void replace(unsigned int oldX,unsigned int oldY,unsigned int newX,unsigned int newY);

    int getElement(unsigned int posX, unsigned int posY);

    void setElement(int element, unsigned int posX, unsigned int posY);

    void setWindow(MainWindow* window);

private:
    std::vector<std::vector<int>> map;
    MainWindow* window;
};

#endif // MAP_H
