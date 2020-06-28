#ifndef ENEMY_H
#define ENEMY_H
#include<QPoint>
#include<tower.h>
#include<money.h>
class Enemy
{
public:
    Enemy(QPoint pos,int type,int m);//利用位置和等级初始化敌人
    Enemy(const Enemy &w);
    QPoint pos();//返回怪物所在点
    void draw(QPainter *painter);
    void move();//敌人移动（左上方）
    void inslow();//进入减速状态
    void outslow();//解除减速状态
    void turn(QPoint p[4]);//变换移动方向
    bool live();//返回存活状态
    int level();//返回等级
    void birth();//怪物出生
    void death();//怪物死亡
    void setreward();//改变金额领取状态
    bool hadreward();//返回金额领取状态
    int reward();//返回奖励金额
    void bite(int & gamehp);//攻击基地
    void attacked(int strength);//敌人被防御塔攻击
    double hp();//返回怪物血量
protected:
    QPoint _pos;//敌人位置
    bool _slow;//是否被减速
    int _slowsecond;//减速时长计数器
    int _type;//怪物类型
    bool _live;//是否生存
    double _speed;//移动速度
    double _hp;//血量
    int _direction;//移动方向
    int _level;//怪物等级
    bool _hadreward;//返回该怪物的奖励金额是否已经被领取
    int _reward;//该怪物被击杀的奖励金额
    QPixmap _picture;
};

#endif // ENEMY_H
