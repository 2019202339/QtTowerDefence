#ifndef ENEMY_H
#define ENEMY_H
#include<QPoint>
#include<tower.h>

class enemy
{
public:
    enemy(QPoint pos);//利用位置初始化敌人
    void move();//敌人移动
    void turn(QPoint p);//变换移动方向
    void death();//敌人死亡
    void bite();//攻击基地
    void attacked(Tower t);//敌人被防御塔攻击
protected:
    QPoint _pos;//敌人位置
    bool _live;//是否生存
    int _speed;//移动速度
    int _hp;//血量
    int _direction;//移动方向
};

#endif // ENEMY_H
