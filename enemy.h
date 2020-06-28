#ifndef ENEMY_H
#define ENEMY_H
#include<QPoint>
#include<tower.h>
#include<money.h>
class Enemy
{
public:
    Enemy(QPoint pos,int type,int m);//����λ�ú͵ȼ���ʼ������
    Enemy(const Enemy &w);
    QPoint pos();//���ع������ڵ�
    void draw(QPainter *painter);
    void move();//�����ƶ������Ϸ���
    void inslow();//�������״̬
    void outslow();//�������״̬
    void turn(QPoint p[4]);//�任�ƶ�����
    bool live();//���ش��״̬
    int level();//���صȼ�
    void birth();//�������
    void death();//��������
    void setreward();//�ı�����ȡ״̬
    bool hadreward();//���ؽ����ȡ״̬
    int reward();//���ؽ������
    void bite(int & gamehp);//��������
    void attacked(int strength);//���˱�����������
    double hp();//���ع���Ѫ��
protected:
    QPoint _pos;//����λ��
    bool _slow;//�Ƿ񱻼���
    int _slowsecond;//����ʱ��������
    int _type;//��������
    bool _live;//�Ƿ�����
    double _speed;//�ƶ��ٶ�
    double _hp;//Ѫ��
    int _direction;//�ƶ�����
    int _level;//����ȼ�
    bool _hadreward;//���ظù���Ľ�������Ƿ��Ѿ�����ȡ
    int _reward;//�ù��ﱻ��ɱ�Ľ������
    QPixmap _picture;
};

#endif // ENEMY_H
