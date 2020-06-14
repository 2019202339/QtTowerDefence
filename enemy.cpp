#include "enemy.h"
#include<QPoint>
#include<math.h>
#include<QMediaPlayer>
#include<money.h>
#include<QPainter>
double distance(QPoint m,QPoint n){
    return sqrt((m.x()-n.x())*(m.x()-n.x())+(m.y()-n.y())*(m.y()-n.y()));
}//内置一个计算距离的函数
Enemy::Enemy(QPoint pos,int type,int level):_pos(pos),_type(type),_live(false),_speed(1),_hp(100*level),_direction(1),_level(level),_hadreward(false),_reward(level*100)
{
    if(_type==1){
        _picture= QPixmap(":/new/prefix1/picture/enemy1.png");
    }
    if(_type==2){
        _picture= QPixmap(":/new/prefix1/picture/enemy2.png");
    }
    if(_type==3){
        _picture= QPixmap(":/new/prefix1/picture/enemy3.png");
    }
    if(_type==4){
        _picture= QPixmap(":/new/prefix1/picture/enemy4.png");
    }
    if(_type==5){
        _picture= QPixmap(":/new/prefix1/picture/enemy5.png");
    }
}
Enemy::Enemy(const Enemy &w):_pos(w._pos),_live(w._live),_speed(w._speed),_hp(w._hp),_direction(w._direction),_level(w._level),_hadreward(w._hadreward),_reward(w._level*100)
{}
QPoint Enemy::pos(){
    return _pos;
}
void Enemy::draw(QPainter *painter){
    painter->save();
    if(_live){
        painter->setBrush(Qt::red);
        painter->drawRect(_pos.x(),_pos.y(),100,_level*5);
        painter->setBrush(Qt::green);
        painter->drawRect(_pos.x(),_pos.y(),_hp/_level,_level*5);//利用矩形组合的方法绘制血槽
        painter->drawPixmap(_pos, _picture);
    }
    painter->restore();
}
void Enemy::move(){//123分别对应右下上三个方向
    switch (_direction){
        case 1:
           _speed=10;
           _pos.setX(_pos.x()+_speed);//向右移动speed单位
           break;
        case 2:
           _speed=9.5;
           _pos.setY(_pos.y()+_speed);//向下移动speed单位
           break;
        case 3:
           _speed=10;
           _pos.setX(_pos.x()-_speed);//向左移动speed单位
           break;
        case 4:
           _speed=9.5;
           _pos.setY(_pos.y()+_speed);//向下移动speed单位
           break;
        case 5:
           _speed=10;
           _pos.setX(_pos.x()+_speed);//向右移动speed单位
           break;
    }
}
void Enemy::turn(QPoint p[4]){
    if(_level==1){//结合怪物的体积大小设置其转向条件
        if(distance(_pos,p[0])<100)
            _direction=2;
        if(distance(_pos,p[1])<100)
            _direction=3;
        if(distance(_pos,p[2])<71)
            _direction=2;
        if(distance(_pos,p[3])<100)
            _direction=1;
    }
    if(_level==2){//结合怪物的体积大小设置其转向条件
        if(distance(_pos,p[0])<100)
            _direction=2;
        if(distance(_pos,p[1])<100)
            _direction=3;
        if(distance(_pos,p[2])<100)
            _direction=2;
        if(distance(_pos,p[3])<100)
            _direction=1;
    }
    if(_level==3){//结合怪物的体积大小设置其转向条件
        if(distance(_pos,p[0])<140)
            _direction=2;
        if(distance(_pos,p[1])<140)
            _direction=3;
        if(distance(_pos,p[2])<95)
            _direction=2;
        if(distance(_pos,p[3])<160)
            _direction=1;
    }
}
bool Enemy::live(){
    return _live;
}
int Enemy::level(){
    return _level;
}
void Enemy::birth(){
    _live=true;
}
void Enemy::death(){
    if(_hp<=0){//hp小于等于0判定怪物死亡
        QMediaPlayer *player1 = new QMediaPlayer;
        player1->setMedia(QUrl("qrc:/new/prefix1/sounds/enemydead.mp3"));
        player1->setVolume(30);
        player1->play();
        _live=false;
    }
}
void Enemy::bite(int & gamehp){
    if(gamehp>=0){
    if(_level<=2){
        if(distance(_pos,QPoint(860,540))<100){
             _hp=0;//怪物攻击基地后自行消失
             gamehp=gamehp-10;
             _hadreward=true;
        }
    }
    if(_level==3){
        if(distance(_pos,QPoint(860,540))<160){
            gamehp=gamehp-10;
            _hp=0;//怪物攻击基地后自行消失
            _hadreward=true;
        }
    }
    }
}
void Enemy::attacked(int strength){
    _hp-=strength;
}
double Enemy::hp(){
    return _hp;
}
void Enemy::setreward(){
    _hadreward=true;
}
bool Enemy::hadreward(){
    return _hadreward;
}
int Enemy::reward(){
    return _reward;
}
