#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamewindow.h"
#include "cursor.h"
#include <QtNetwork>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(Map *terrainMap,Map *unitMap,Cursor* cursor);
    void keyPressEvent(QKeyEvent * event);
    GameWindow* getWidget();
    void updateWidget();

public slots:
    void onNewConnection();
    void onConnected();
    void onDisconnected();
    void onData();

private:
    int unitPosX;
    int unitPosY;
    Cursor* cursor;
    GameWindow centerZone;
    int cursorState;
    QTcpServer* server = nullptr;
    QTcpSocket* other = nullptr;
    quint32 currentSize = 0;
    void sendJson(QJsonObject obj);
    bool isConfigured=false;

signals:

public slots:
    void switchPlayer();
    void updateWin();
    void movingUnit();
};

#endif // MAINWINDOW_H
