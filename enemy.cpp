#include "enemy.h"
#include<QPoint>
#include<math.h>
double distance(QPoint m,QPoint n){
    return sqrt((m.x()-n.x())*(m.x()-n.x())+(m.y()-n.y())*(m.y()-n.y()));
}
Enemy::Enemy(QPoint pos,int level):_pos(pos),_live(false),_speed(1),_hp(100*level),_direction(1),_level(level)
{}
QPoint Enemy::pos(){
    return _pos;
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
    if(_level==1){
        if(distance(_pos,p[0])<50)
            _direction=2;
        if(distance(_pos,p[1])<50)
            _direction=3;
        if(distance(_pos,p[2])<35.5)
            _direction=2;
        if(distance(_pos,p[3])<50)
            _direction=1;
    }
    if(_level==2){
        if(distance(_pos,p[0])<50)
            _direction=2;
        if(distance(_pos,p[1])<50)
            _direction=3;
        if(distance(_pos,p[2])<37.5)
            _direction=2;
        if(distance(_pos,p[3])<50)
            _direction=1;
    }
    if(_level==3){
        if(distance(_pos,p[0])<70)
            _direction=2;
        if(distance(_pos,p[1])<70)
            _direction=3;
        if(distance(_pos,p[2])<47.5)
            _direction=2;
        if(distance(_pos,p[3])<80)
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
    if(_hp<=0)//hp小于等于0判定怪物死亡
        _live=false;
}
void Enemy::bite(){
    if(_level<=2){
        if(distance(_pos,QPoint(430,270))<50)
        _hp=0;//怪物攻击基地后自行消失
    }
    if(_level==3){
        if(distance(_pos,QPoint(430,270))<80)
        _hp=0;//怪物攻击基地后自行消失
    }
}
