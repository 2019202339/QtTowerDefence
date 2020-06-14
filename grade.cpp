#include "grade.h"
Grade::Grade(){}
Grade::Grade(int grade):_grade(grade)
{}
void Grade::getgrade(Enemy e[15],Tower t[12], Money m, int hp, int gamespeed,bool win){
    for(int i=0;i<15;i++){
        if(e[i].live())
            _g0+=1;
    }
    for(int i=0;i<12;i++){
        if(t[i].live()){
            if(t[i].mostlevel()){
                _g1+=2;
            }
            else
                _g1+=1;
        }
    }
    _g2=m.getamount();
    _g3=hp;
    _g4=gamespeed;
    if(win)
        _g5=1000;

    else
        _g5=-1000;
    _grade=_g2*2+_g3*3+_g4*200-_g1*100+_g5-_g0*500;
}
void Grade::drawgrade(QPainter *painter){
        QFont font("Arial",20,QFont::Bold,true);
        painter->setFont(font);
        painter->setPen(Qt::yellow);//设置画笔颜色为黄色
        QRect p1=QRect(182,172,600,60);
        painter->drawText(p1,Qt::AlignCenter,"YOUR GRADE:"+QString::number(_grade));
        QRect p2=QRect(182,232,600,50);
        painter->drawText(p2,Qt::AlignCenter,"Enemy Lived:"+QString::number(_g0));
        QRect p3=QRect(182,282,600,50);
        painter->drawText(p3,Qt::AlignCenter,"Tower Exist:"+QString::number(_g1));
        QRect p4=QRect(182,332,600,50);
        painter->drawText(p4,Qt::AlignCenter,"Money:"+QString::number(_g2));
        QRect p5=QRect(182,382,600,50);
        painter->drawText(p5,Qt::AlignCenter,"Hp:"+QString::number(_g3));
        QRect p6=QRect(182,432,600,50);
        painter->drawText(p6,Qt::AlignCenter,"Game Speed:X"+QString::number(_g4));
        _g0=0;
        _g1=0;
    }
