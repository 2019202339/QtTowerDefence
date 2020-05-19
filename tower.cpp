#include "tower.h"
#include "mainwindow.h"
#include <QPainter>

Tower::Tower(const QPoint a,MainWindow *game):
    _pos(a),_game(game),_range(80),_strength(10),_rate(10)
{}
