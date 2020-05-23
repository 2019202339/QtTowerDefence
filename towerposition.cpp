#include "towerposition.h"
#include<QPoint>
#include<QPainter>
const QSize TowerPosition::_fixedsize(44,44);//根据可置点的大小设定点击识别范围

TowerPosition::TowerPosition(QPoint pos):
    _pos(pos),_hastower(false)
{}

const QPoint TowerPosition::getPos() const{
    return _pos;
}

const QPoint TowerPosition::centerPos() const{
    QPoint halfpoint(_fixedsize.width()/2,_fixedsize.height()/2);
    return _pos+halfpoint;
}

bool TowerPosition::containPoint(const QPoint &p) const{
    bool Xin=_pos.x()<p.x()&&p.x()<(_pos.x()+_fixedsize.width());
    bool Yin=_pos.y()<p.y()&&p.y()<(_pos.y()+_fixedsize.height());
    return Xin && Yin;
}

bool TowerPosition::hastower() const{
    return _hastower;
}

void TowerPosition::settower(){
    _hastower=true;
}
void TowerPosition::nosettower(){
    _hastower=false;
}
