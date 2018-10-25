#ifndef TERRAIN_H
#define TERRAIN_H


class Terrain//:public GameObject
{
protected:
    int position[2];
    int defense;
    int apparence;
public:
    Terrain(int pos[2], int def, int app);
    int getPositionX() const;
    int getPositionY() const;
    int getDefense() const;
    int getApparence() const;
};

#endif // TERRAIN_H
