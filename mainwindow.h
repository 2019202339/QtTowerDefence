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
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void timerEvent(QTimerEvent *event);
    void checkgame();
    void setspeed(int speed);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    bool win=false;
    bool lost=false;
    int game_speed=1;
    int hp=100;
    Grade grade=Grade(0);
    Money money=Money(300);
    QPoint turnpoint[4]=//��ʼ��4��ת���
    {
        QPoint(890, 200),
        QPoint(890, 390),
        QPoint(0, 390),
        QPoint(0, 580)
    };
    TowerPosition pos[12] =//��ʼ��12����λ
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
    Tower tower[12] =//��ʼ��12����
    {
            Tower(QPoint(130, 440)),
            Tower(QPoint(310, 440)),
            Tower(QPoint(490, 440)),
            Tower(QPoint(670, 440)),

            Tower(QPoint(200, 250)),
            Tower(QPoint(380, 250)),
            Tower(QPoint(560, 250)),
            Tower(QPoint(740, 250)),

            Tower(QPoint(160, 70)),
            Tower(QPoint(340, 70)),
            Tower(QPoint(520, 70)),
            Tower(QPoint(700, 70))
    };

    Enemy enemy[15]=//��ʼ��15ֻ��ͬ�ȼ�������ڻ���Բ����͹����������н�һ���Ż���Ŀǰ�ݶ�Ϊ15ֻ��
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
