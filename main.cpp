#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Map map("Map1V1.txt");
    MainWindow w(&map);
    w.show();

    return app.exec();
}
