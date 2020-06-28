#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<towerposition.h>
#include<tower.h>
#include<QList>
#include<QMouseEvent>
#include<QTimerEvent>
#include<enemy.h>
#include <money.h>
#include <grade.h>
#include <wave.h>
#include <bullet.h>
namespace Ui {
class MainWindow;
}
using namespace std;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void timerEvent(QTimerEvent *event);
    void checkgame();
    void addBullet(Bullet *bullet);
    void removedBullet(Bullet *bullet);
    void setspeed(int speed);
    int getspeed();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    bool win=false;
    bool lost=false;
    int game_speed=1;
    int hp=100;
    Grade grade=Grade(0);
    Money money=Money(300);
    Wave wave=Wave(this);
    QList<Bullet *>	_bulletList;
    QPoint turnpoint[4]=//初始化4个转弯点
    {
        QPoint(890, 200),
        QPoint(890, 390),
        QPoint(0, 390),
        QPoint(0, 580)
    };
    TowerPosition pos[12] =//初始化12个塔位
    {
        TowerPosition(QPoint(130, 440)),
        TowerPosition(QPoint(310, 440)),
        TowerPosition(QPoint(490, 440)),
        TowerPosition(QPoint(670, 440)),

        TowerPosition(QPoint(200, 250)),
        TowerPosition(QPoint(380, 250)),
        TowerPosition(QPoint(560, 250)),
        TowerPosition(QPoint(740, 250)),

        TowerPosition(QPoint(160, 70)),
        TowerPosition(QPoint(340, 70)),
        TowerPosition(QPoint(520, 70)),
        TowerPosition(QPoint(700, 70))
    };
    Tower tower[12] =//初始化12座塔
    {
            Tower(QPoint(130, 440),this),
            Tower(QPoint(310, 440),this),
            Tower(QPoint(490, 440),this),
            Tower(QPoint(670, 440),this),

            Tower(QPoint(200, 250),this),
            Tower(QPoint(380, 250),this),
            Tower(QPoint(560, 250),this),
            Tower(QPoint(740, 250),this),

            Tower(QPoint(160, 70),this),
            Tower(QPoint(340, 70),this),
            Tower(QPoint(520, 70),this),
            Tower(QPoint(700, 70),this)
    };

    Enemy enemy[15]=//初始化15只不同等级怪物（后期还会对波数和怪物数量进行进一步优化，目前暂定为15只）
    {
        Enemy(QPoint(0,140),1,1),
        Enemy(QPoint(0,140),2,1),
        Enemy(QPoint(0,140),1,1),
        Enemy(QPoint(0,140),2,1),
        Enemy(QPoint(0,140),1,1),
        Enemy(QPoint(0,140),2,1),
        Enemy(QPoint(0,140),1,1),
        Enemy(QPoint(0,120),3,2),
        Enemy(QPoint(0,120),4,2),
        Enemy(QPoint(0,120),3,2),
        Enemy(QPoint(0,120),4,2),
        Enemy(QPoint(0,120),3,2),
        Enemy(QPoint(0,120),4,2),
        Enemy(QPoint(0,80),5,3),
        Enemy(QPoint(0,80),5,3)
    };
};

#endif // MAINWINDOW_H
