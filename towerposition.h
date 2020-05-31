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
    void nosettower();//拆除防御塔
    bool hastower() const;//判断是否有防御塔
    const QPoint getPos() const;//返回塔位的坐标（左上角坐标）
    bool containPoint(const QPoint &p) const;//判断点击位置是否可置

protected:
    QPoint _pos;
    bool _hastower;
    static const QSize _fixedsize;
};

#endif // TOWERPOSITION_H
