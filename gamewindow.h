#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include "map.h"

class GameWindow : public QWidget
{
    Q_OBJECT
public:
    explicit GameWindow(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);
    void setMap(Map *map);
private:
    Map *map;
signals:

public slots:
};

#endif // GAMEWINDOW_H
