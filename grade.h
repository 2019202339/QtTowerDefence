#ifndef GRADE_H
#define GRADE_H
#include <tower.h>
#include <money.h>
#include <enemy.h>
#include <QPainter>
class Grade
{
public:
    Grade();
    Grade(int grade);
    void drawgrade(QPainter *painter);
    void getgrade(Enemy e[15],Tower t[12],Money m,int hp,int gamespeed,bool win);
private:
    double _grade;//�ܵ÷�
    double _g0;//���˴��
    double _g1;//����������
    double _g2;//��Ǯʣ��
    double _g3;//hpʣ��
    double _g4;//��Ϸ�Ѷ�
    double _g5;//ʤ�ܵ÷�
};

#endif // GRADE_H
