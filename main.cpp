#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include "mainmenu.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainMenu m;
    m.show();
    return app.exec();
}
