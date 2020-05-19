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
    bool hastower() const;//�ж��Ƿ��з�����
    const QPoint centerPos() const;//���ظ�λ�õ����ĵ�
    bool containPoint(const QPoint &p) const;//�жϵ��λ���Ƿ���õ�
    void drawtower(QPainter *painter) const;

protected:
    QPoint _pos;
    bool _hastower;
    QPixmap _sprite;
    static const QSize _fixedsize;
};

#endif // TOWERPOSITION_H
