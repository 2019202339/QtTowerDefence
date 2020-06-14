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
    double _grade;//总得分
    double _g0;//敌人存活
    double _g1;//防御塔建造
    double _g2;//金钱剩余
    double _g3;//hp剩余
    double _g4;//游戏难度
    double _g5;//胜败得分
};

#endif // GRADE_H
