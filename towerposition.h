#ifndef TOWERPOSITION_H
#define TOWERPOSITION_H
#include<QPoint>
#include<QPixmap>
#include<QSize>


class TowerPosition//设置一个类，判断每一个点是否可以存放塔
{
public:
    TowerPosition(QPoint pos);
    void settower();//放置防御塔
    bool hastower() const;//判断是否有防御塔
    const QPoint centerPos() const;//返回该位置的中心点
    bool containPoint(const QPoint &p) const;//判断点击位置是否可置点
    void drawtower(QPainter *painter) const;

protected:
    QPoint _pos;
    bool _hastower;
    QPixmap _sprite;
    static const QSize _fixedsize;
};

#endif // TOWERPOSITION_H
