#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Map terrainMap("Map1V1.txt");
    Map UnitMap(terrainMap.getSize('m'),terrainMap.getSize('p'));
    MainWindow w(&terrainMap);
    w.show();

    return app.exec();
}
