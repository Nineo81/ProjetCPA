#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include "map.h"
#include "cursor.h"

class GameWindow : public QWidget
{
    Q_OBJECT
public:
    explicit GameWindow(Map *terrainMap=nullptr,Map *unitMap=nullptr,Cursor* cursor=nullptr);

    void paintEvent(QPaintEvent *event);
    void updateMap();
private:
    Map *terrainMap;
    Map *unitMap;
    Cursor* cursor;
signals:

public slots:
};

#endif // GAMEWINDOW_H
