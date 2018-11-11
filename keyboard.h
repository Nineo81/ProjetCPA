#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <QKeyEvent>
#include "game.h"


class Keyboard:public QWidget
{
public:
    Keyboard(Game* game);

    void keyPressEvent(QKeyEvent * event);

private:
    Game* game;
};

#endif // KEYBOARD_H
