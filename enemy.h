#ifndef ENEMY_H
#define ENEMY_H
#include<QPoint>
#include<tower.h>

class enemy
{
public:
    enemy(QPoint pos);//����λ�ó�ʼ������
    void move();//�����ƶ�
    void turn(QPoint p);//�任�ƶ�����
    void death();//��������
    void bite();//��������
    void attacked(Tower t);//���˱�����������
protected:
    QPoint _pos;//����λ��
    bool _live;//�Ƿ�����
    int _speed;//�ƶ��ٶ�
    int _hp;//Ѫ��
    int _direction;//�ƶ�����
};

#endif // ENEMY_H
