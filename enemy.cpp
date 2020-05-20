#include "enemy.h"
#include<QPoint>
enemy::enemy(QPoint pos):
    _pos(pos),_live(true),_speed(10),_hp(100),_direction(1)
{}
void enemy::move(){//123分别对应右下上三个方向
    switch (_direction){
        case 1:
           _pos.setX(_pos.x()+_speed);//向右移动speed单位
           break;
        case 2:
           _pos.setY(_pos.y()+_speed);//向下移动speed单位
           break;
        case 3:
           _pos.setX(_pos.x()-_speed);//向左移动speed单位
    }
}
void enemy::turn(QPoint p){
    int m=0;//引入计数量根据地图调整方向
    if(abs(_pos.x()-p.x())<2&&m<2){//在前两个拐点分别实现向下和向左
        _direction+=1;
        m+=1;
    }
    else if(abs(_pos.x()-p.x())<2&&m>=2){//在后两个拐点分别实现向下和向右
        _direction-=1;
    }
}
void enemy::death(){
    if(_hp<=0)//hp小于等于0判定怪物死亡
        _live=false;
}
void enemy::bite(){
    _hp=0;//怪物攻击基地后自行消失
}
