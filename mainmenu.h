#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <vector>
#include "custombutton.h"
using namespace std;

class MainMenu : public QWidget
{
    Q_OBJECT
public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();
private:
    vector<CustomButton*> listButton;
    QStringList text;
signals:

public slots:
    void creatGame(int gameType);
};

#endif // MAINMENU_H
