#ifndef CURSOR_H
#define CURSOR_H


class Cursor
{
public:
    Cursor(int posX,int posY);
    void move(int up,int left,int down,int right);
private:
    int posX;
    int posY;
};

#endif // CURSOR_H
