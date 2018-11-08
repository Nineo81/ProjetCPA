#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Map terrainMap("Map1V1.txt");       //attribut du game +constructeur
    Map UnitMap(terrainMap.getSize('m'),terrainMap.getSize('p'));       //attribut du game +constructeur
    MainWindow w(&terrainMap);      //atttribut du game ?? +constructeur
    w.show();

    return app.exec();
}
