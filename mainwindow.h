#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamewindow.h"
#include "cursor.h"
#include <QtNetwork>

class AI;
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(Map *terrainMap,Map *unitMap,Cursor* cursor);
    void keyPressEvent(QKeyEvent * event) override;
    void mousePressEvent(QMouseEvent *ev) override;
    int typeOfUnitMenu(int moveState);
    GameWindow* getWidget();
    void updateWidget();
    void moved(QMouseEvent *event);
    bool getInactiveAI() const;
    void setAI(AI *value);
    AI *getAI() const;
    bool getPathfindAI() const;

private:
    unsigned int unitPosX;
    unsigned int unitPosY;
    Cursor* cursor;
    GameWindow centerZone;
    int cursorState;
    QTcpServer* server = nullptr;
    QTcpSocket* other = nullptr;
    quint32 currentSize = 0;
    void sendJson(QJsonObject obj);
    bool isConfigured=false;
    bool reseau = false;
    bool myTurn = true;
    bool inactiveAI = false;
    bool pathfindAI = true;
    AI* ai = nullptr;

signals:
    void mouseMoved();
    void passedTurn();

public slots:
    void switchPlayer();
    void updateWin();
    void movingUnit();
    void setUnitWainting();
    void unitAttack();
    void unitCapture();
    void onNewConnection();
    void onConnected();
    void onDisconnected();
    void onData();
    void createUnit();
    void curState();
};

#endif // MAINWINDOW_H
