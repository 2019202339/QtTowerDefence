#ifndef TOWERPOSITION_H
#define TOWERPOSITION_H
#include<QPoint>
#include<QPixmap>
#include<QSize>


class TowerPosition//����һ���࣬�ж�ÿһ�����Ƿ���Դ����
{
public:
    TowerPosition(QPoint pos);
    void settower();//���÷�����
    void nosettower();//���������
    bool hastower() const;//�ж��Ƿ��з�����
    const QPoint getPos() const;//������λ�����꣨���Ͻ����꣩
    bool containPoint(const QPoint &p) const;//�жϵ��λ���Ƿ����

protected:
    QPoint _pos;
    bool _hastower;
    static const QSize _fixedsize;
};

#endif // TOWERPOSITION_H
