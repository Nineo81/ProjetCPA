#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamewindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(Map *terrainMap,Map *unitMap);
    void keyPressEvent(QKeyEvent * event);
    GameWindow* getWidget();

private:
    GameWindow centerZone;

signals:

public slots:
};

#endif // MAINWINDOW_H
