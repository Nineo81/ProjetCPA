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
    void setEscape(bool escape);
private:
    bool escape;
signals:
    void moveUnit();
    void waiting();
    void capturing();
    void attacking();
public slots:
    void movement();
    void unitWait();
    void capture();
    void attack();
};

#endif // UNITMENU_H
