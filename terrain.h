#ifndef TERRAIN_H
#define TERRAIN_H


class Terrain//:public GameObject
{
protected:
    int position[2];
    int defense;
public:
    Terrain(int pos[2], int def);
    int getPositionX() const;
    int getPositionY() const;
    int getDefense() const;
};

#endif // TERRAIN_H
