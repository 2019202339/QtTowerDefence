#ifndef MONEY_H
#define MONEY_H
#include<QString>
#include<QPainter>
class Money
{
public:
    Money();
    Money(int money);//�������ֳ�ʼ��һ�����ϵͳ
    int getamount();//���ص�ǰ�������
    void draw(QPainter *painter);
    Money operator +(int amount);//�������㷨����ʵ�ֽ�������Ӷ���
    Money operator -(int amount);//���ò���������ʵ�ֽ�������ٶ���
    bool canbuy(int amount);//���һ���ض��۸��ж��Ƿ�ǰ����������Թ������Ʒ
private:
    int _amount;//�������
};

#endif // MONEY_H
