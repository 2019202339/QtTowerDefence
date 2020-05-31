#include "tower.h"
#include "mainwindow.h"
#include <QPainter>
#include <enemy.h>
#include <QMediaPlayer>
#include<QSize>
QMediaPlayer *player2 = new QMediaPlayer;
double distance1(QPoint m,QPoint n){
    return sqrt((m.x()-n.x())*(m.x()-n.x())+(m.y()-n.y())*(m.y()-n.y()));
}
Tower::Tower(const QPoint a):
    _pos(a),_range(120),_strength(10),_rate(10),_live(false),_mostlevel(false),_hastarget(false),_target(-1),_price(100)
{}
void Tower::draw(QPainter *painter){
    if(_live){//绘制防御塔
        painter->drawPixmap(_pos,_picture);
        painter->setPen(Qt::white);
        painter->drawEllipse(centerPos(),_range,_range);//绘制攻击范围
}
}
const QPoint Tower::centerPos() const{
    QPoint halfpoint(44,44);
    return _pos+halfpoint;
}

int Tower::range(){
    return _range;
}
void Tower::build(){    
    player2->setMedia(QUrl("qrc:/new/prefix1/sounds/tower1birth.mp3"));
    player2->setVolume(30);
    _live=true;
    _picture=QPixmap(":/new/prefix1/picture/tower.png");
    player2->play();
}
bool Tower::live(){
    return _live;
}
void Tower::build1(){
    player2->setMedia(QUrl("qrc:/new/prefix1/sounds/tower1birth.mp3"));
    player2->setVolume(30);
    _live=true;
    _mostlevel=true;
    _range=180;
    _strength=20;//参数随之升级
    _picture=QPixmap(":/new/prefix1/picture/tower2.png");
    player2->play();
}
void Tower::uninstall(){
    player2->setMedia(QUrl("qrc:/new/prefix1/sounds/crash.mp3"));
    player2->setVolume(30);
    player2->play();
    _mostlevel=false;
    _live=false;
    _range=120;
    _strength=50;
    _picture=QPixmap(":/new/prefix1/picture/tower.png");//将所有参数回复到未激活状态
}
bool Tower::mostlevel(){
    return _mostlevel;
}
bool Tower::hastarget(){
    return _hastarget;
}
void Tower::attack(Enemy enemy[15]){//塔的攻击函数
    if(hastarget()==false){//如果防御没有攻击目标
        for(int i=0;i<15;i++){//遍历所有怪物
            if(distance1(enemy[i].pos(),_pos)<=_range&&enemy[i].live()){//寻找遍历到的第一个在防御塔攻击范围内的存活怪物
                _hastarget=true;
                _target=i;//将这一怪物设定为该塔的攻击目标
                break;//结束对怪物的遍历
            }
        }
    }
    if(hastarget()&&enemy[_target].live()){//在拥有攻击目标且攻击目标存活的情况下
        if(distance1(enemy[_target].pos(),_pos)<=_range&&enemy[_target].live()){//如果目标在攻击范围内
            enemy[_target].attacked(_strength);//对怪物进行攻击
        }
        else if(distance1(enemy[_target].pos(),_pos)>_range)//如果攻击目标离开攻击范围
            _hastarget=false;//失去该目标
    }
    if(hastarget()&&!enemy[_target].live()){//如果攻击目标死亡
        _hastarget=false;//失去该目标
    }
}
int Tower::price(){
    return _price;
}
