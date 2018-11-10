#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include "game.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Game* g = new Game();
    return app.exec();
}
