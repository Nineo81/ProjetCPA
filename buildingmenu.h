#ifndef BUILDINGMENU_H
#define BUILDINGMENU_H

#include <QWidget>
#include <QKeyEvent>
#include <QCloseEvent>
#include <vector>
#include "custombutton.h"
#include "building.h"
using namespace std;

class BuildingMenu : public QWidget
{
    Q_OBJECT
public:
    explicit BuildingMenu(int posX, int posY,Building* building);
    ~BuildingMenu();
    void keyPressEvent(QKeyEvent * event);
    void isCLosing(QCloseEvent *event);
    void focusOutEvent(QFocusEvent* event);
private:
    Building* building;
    vector<CustomButton*> listButton;
    QStringList text;
signals:
    void qMenuClose();
    void createU();
    void menuClose();

public slots:
    void create(int type);
};

#endif // BUILDINGMENU_H
