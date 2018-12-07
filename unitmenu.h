#ifndef UNITMENU_H
#define UNITMENU_H

#include <QWidget>
#include <QKeyEvent>

class UnitMenu : public QWidget
{
    Q_OBJECT
public:
    explicit UnitMenu(int posX, int posY);
    void keyPressEvent(QKeyEvent * event);
signals:
    void moveUnit();

public slots:
    void movement();
};

#endif // UNITMENU_H
