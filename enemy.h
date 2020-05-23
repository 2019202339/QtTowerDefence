#ifndef ENEMY_H
#define ENEMY_H
#include<QPoint>
#include<tower.h>

class Enemy
{
public:
    Enemy(QPoint pos,int m);//利用位置和等级初始化敌人
    QPoint pos();//返回怪物所在点
    void move();//敌人移动（左上方）
    void turn(QPoint p[4]);//变换移动方向
    bool live();//返回存活状态
    int level();//返回等级
    void birth();//怪物出生
    void death();//怪物死亡
    void bite();//攻击基地
    void attacked(Tower t);//敌人被防御塔攻击
protected:
    QPoint _pos;//敌人位置
    bool _live;//是否生存
    double _speed;//移动速度
    int _hp;//血量
    int _direction;//移动方向
    int _level;//怪物等级
};

#endif // ENEMY_H
