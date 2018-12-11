#ifndef UNITMENU_H
#define UNITMENU_H

#include <QWidget>
#include <QKeyEvent>

class UnitMenu : public QWidget
{
    Q_OBJECT
public:
    explicit UnitMenu(int posX, int posY, int type);
    void keyPressEvent(QKeyEvent * event);
signals:
    void moveUnit();
    void waiting();
public slots:
    void movement();
    void unitWait();
};

#endif // UNITMENU_H
