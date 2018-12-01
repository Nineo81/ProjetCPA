#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamewindow.h"
#include "cursor.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(Map *terrainMap,Map *unitMap,Cursor* cursor);
    void keyPressEvent(QKeyEvent * event);
    GameWindow* getWidget();
    void updateWidget();

private:
    Cursor* cursor;
    GameWindow centerZone;

signals:

public slots:
};

#endif // MAINWINDOW_H
