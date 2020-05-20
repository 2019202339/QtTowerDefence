#include "enemy.h"
#include<QPoint>
enemy::enemy(QPoint pos):
    _pos(pos),_live(true),_speed(10),_hp(100),_direction(1)
{}
void enemy::move(){//123�ֱ��Ӧ��������������
    switch (_direction){
        case 1:
           _pos.setX(_pos.x()+_speed);//�����ƶ�speed��λ
           break;
        case 2:
           _pos.setY(_pos.y()+_speed);//�����ƶ�speed��λ
           break;
        case 3:
           _pos.setX(_pos.x()-_speed);//�����ƶ�speed��λ
    }
}
void enemy::turn(QPoint p){
    int m=0;//������������ݵ�ͼ��������
    if(abs(_pos.x()-p.x())<2&&m<2){//��ǰ�����յ�ֱ�ʵ�����º�����
        _direction+=1;
        m+=1;
    }
    else if(abs(_pos.x()-p.x())<2&&m>=2){//�ں������յ�ֱ�ʵ�����º�����
        _direction-=1;
    }
}
void enemy::death(){
    if(_hp<=0)//hpС�ڵ���0�ж���������
        _live=false;
}
void enemy::bite(){
    _hp=0;//���﹥�����غ�������ʧ
}
