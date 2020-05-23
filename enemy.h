#ifndef ENEMY_H
#define ENEMY_H
#include<QPoint>
#include<tower.h>

class Enemy
{
public:
    Enemy(QPoint pos,int m);//����λ�ú͵ȼ���ʼ������
    QPoint pos();//���ع������ڵ�
    void move();//�����ƶ������Ϸ���
    void turn(QPoint p[4]);//�任�ƶ�����
    bool live();//���ش��״̬
    int level();//���صȼ�
    void birth();//�������
    void death();//��������
    void bite();//��������
    void attacked(Tower t);//���˱�����������
protected:
    QPoint _pos;//����λ��
    bool _live;//�Ƿ�����
    double _speed;//�ƶ��ٶ�
    int _hp;//Ѫ��
    int _direction;//�ƶ�����
    int _level;//����ȼ�
};

#endif // ENEMY_H
