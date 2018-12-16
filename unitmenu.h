#ifndef UNITMENU_H
#define UNITMENU_H

#include <QWidget>
#include <QKeyEvent>
#include <QPushButton>
#include <vector>

class UnitMenu : public QWidget
{
    Q_OBJECT
public:
    explicit UnitMenu(int posX, int posY, int type);
    ~UnitMenu();
    void keyPressEvent(QKeyEvent * event);
    void setEscape(bool escape);
    void focusOutEvent(QFocusEvent* event);
    void forceResp();
private:
    std::vector<QPushButton*> listButton;
    QStringList text;
    bool forceResponse=false;
    bool escape;
signals:
    void moveUnit();
    void waiting();
    void capturing();
    void attacking();
    void menuClose();
public slots:
    void movement();
    void unitWait();
    void capture();
    void attack();
};

#endif // UNITMENU_H
