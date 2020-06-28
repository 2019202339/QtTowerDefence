#include "money.h"
#include "QString"
Money::Money(){}
Money::Money(int money):_amount(money)
{}
void Money::draw(QPainter *painter){
    QFont font("Arial",20,QFont::Bold,true);
    painter->setFont(font);
    painter->setPen(Qt::yellow);//设置画笔颜色为黄色
    painter->drawText(300,30,"Money:"+QString::number(_amount));
}
Money Money::operator +(int amount){
    _amount+=amount;
    return *this;
}
Money Money::operator -(int amount){
    _amount-=amount;
    return *this;
}
int Money::getamount(){
    return _amount;
}
bool Money::canbuy(int amount){
    if(_amount>=amount)
        return true;
    else
        return false;
}
