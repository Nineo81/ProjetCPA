#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include "map.h"
#include "cursor.h"
#include <vector>

class GameWindow : public QWidget
{
    Q_OBJECT
public:
    explicit GameWindow(Map *terrainMap=nullptr,Map *unitMap=nullptr,Cursor* cursor=nullptr);

    void paintEvent(QPaintEvent *event);
    void setSize(double width,double height);
    void updateMap();
    void movementsReset();
    void setMovements(vector<vector<int>> movements);
    int getSizePicture();
private:
    int sizePicture;
    unsigned int height;
    unsigned int width;
    Map *terrainMap;
    Map *unitMap;
    Cursor* cursor;
    std::vector<QImage> listImage;
    std::vector<vector<int>> movements;
signals:

public slots:
};

#endif // GAMEWINDOW_H
