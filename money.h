#ifndef MONEY_H
#define MONEY_H
#include<QString>
#include<QPainter>
class Money
{
public:
    Money();
    Money(int money);//利用数字初始化一个金币系统
    int getamount();//返回当前金币数量
    void draw(QPainter *painter);
    Money operator +(int amount);//利用运算法重载实现金币量增加动作
    Money operator -(int amount);//利用操作符重载实现金币量减少动作
    bool canbuy(int amount);//针对一个特定价格，判断是否当前金币数量可以购买该商品
private:
    int _amount;//金币数量
};

#endif // MONEY_H
