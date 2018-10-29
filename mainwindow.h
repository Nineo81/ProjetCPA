#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamewindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent * event);

private:
    GameWindow centerZone;

signals:

public slots:
};

#endif // MAINWINDOW_H
