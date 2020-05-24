#ifndef TOWER_H
#define TOWER_H
#include <QPoint>
#include <QSize>
#include <QPixmap>
class QPainter;
class MainWindow;
class Enemy;
class Tower
{
public:
    Tower(QPoint p);//用位置对塔进行初始化
    int range();//返回塔的攻击范围
    bool live();//判断塔的存在
    bool mostlevel();//判断塔的等级
    void build();//在空置塔位建造塔
    void build1();//针对已经存在的塔升级
    void uninstall();//对塔进行拆除
    bool hastarget();//判断塔是否已经拥有攻击对象
    void attack(Enemy enemy[15]);//塔的攻击动作



protected:
    QPoint _pos;//塔的位置
    int _range;//塔的攻击范围
    int _strength;//塔的伤害值
    int _rate;//塔的攻击频率
    bool _live;//塔是否存在
    bool _mostlevel;//塔是否升到最高级
    bool _hastarget;//塔是否拥有攻击对象
    int _target;//塔的攻击目标

};

#endif // TOWER_H
