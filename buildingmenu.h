#ifndef BUILDINGMENU_H
#define BUILDINGMENU_H

#include <QWidget>
#include <QKeyEvent>
#include <QCloseEvent>
#include "building.h"

class BuildingMenu : public QWidget
{
    Q_OBJECT
public:
    explicit BuildingMenu(int posX, int posY,Building* building);
    void keyPressEvent(QKeyEvent * event);
    void isCLosing(QCloseEvent *event);
private:
    Building* building;
signals:
    void qMenuClose();
    void createIn();

public slots:
    void create1();
};

#endif // BUILDINGMENU_H
