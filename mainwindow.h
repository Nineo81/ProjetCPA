#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Map.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent* event);
    void setMap(Map *map);

private:

    Map *map;

signals:

public slots:
};

#endif // MAINWINDOW_H
