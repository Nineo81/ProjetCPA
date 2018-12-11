#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include <QWidget>
#include <QKeyEvent>

class PauseMenu : public QWidget
{
    Q_OBJECT
public:
    explicit PauseMenu(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent * event);
signals:
    void nextPlayer();
    void ending();
public slots:
    void passTurn();
    void endGame();
};

#endif // PAUSEMENU_H
