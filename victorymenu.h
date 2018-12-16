#ifndef VICTORYMENU_H
#define VICTORYMENU_H

#include <QWidget>

class VictoryMenu : public QWidget
{
    Q_OBJECT
public:
    explicit VictoryMenu(const QString & text);

signals:
    void endingGame();
public slots:
    void ending();
};

#endif // VICTORYMENU_H
