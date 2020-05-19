#ifndef TOWER_H
#define TOWER_H
#include <QPoint>
#include <QSize>
#include <QPixmap>
class QPainter;
class MainWindow;

class Tower
{
public:
    Tower(QPoint p,MainWindow *game);

protected:
    QPoint _pos;
    MainWindow *_game;
    int _range;
    int _strength;
    int _rate;
};

#endif // TOWER_H
