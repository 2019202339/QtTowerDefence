#include "tower.h"
#include "mainwindow.h"
#include <QPainter>

Tower::Tower(const QPoint a):
    _pos(a),_range(60),_strength(10),_rate(10),_live(false),_mostlevel(false)
{}
int Tower::range(){
    return _range;
}
void Tower::build(){
    _live=true;
}
bool Tower::live(){
    return _live;
}
void Tower::build1(){
    _mostlevel=true;
    _range=90;
    _strength=20;
}
void Tower::uninstall(){
    _mostlevel=false;
    _live=false;
}
bool Tower::mostlevel(){
    return _mostlevel;
}
