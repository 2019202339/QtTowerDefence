#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<towerposition.h>
#include<tower.h>
#include<QList>
#include<QMouseEvent>
#include<QTimerEvent>
#include<enemy.h>
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
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPoint point[12] =//��ʼ��12����̨��
    {
        QPoint(65, 220),
        QPoint(155, 220),
        QPoint(245, 220),
        QPoint(335, 220),

        QPoint(100, 125),
        QPoint(195, 125),
        QPoint(280, 125),
        QPoint(370, 125),

        QPoint(80, 35),
        QPoint(170, 35),
        QPoint(260, 35),
        QPoint(350, 35)
    };
    QPoint turnpoint[4]=//��ʼ��4��ת���
    {
        QPoint(445, 100),
        QPoint(445, 195),
        QPoint(0, 195),
        QPoint(0, 290)
    };
    TowerPosition pos[12] =//��ʼ��12����λ
    {
        TowerPosition(QPoint(65, 220)),
        TowerPosition(QPoint(155, 220)),
        TowerPosition(QPoint(245, 220)),
        TowerPosition(QPoint(335, 220)),

        TowerPosition(QPoint(100, 125)),
        TowerPosition(QPoint(195, 125)),
        TowerPosition(QPoint(280, 125)),
        TowerPosition(QPoint(370, 125)),

        TowerPosition(QPoint(80, 35)),
        TowerPosition(QPoint(170, 35)),
        TowerPosition(QPoint(260, 35)),
        TowerPosition(QPoint(350, 35))
    };
    Tower tower[12] =//��ʼ��12����
    {
        Tower(QPoint(65, 220)),
        Tower(QPoint(155, 220)),
        Tower(QPoint(245, 220)),
        Tower(QPoint(335, 220)),

        Tower(QPoint(100, 125)),
        Tower(QPoint(195, 125)),
        Tower(QPoint(280, 125)),
        Tower(QPoint(370, 125)),

        Tower(QPoint(80, 35)),
        Tower(QPoint(170, 35)),
        Tower(QPoint(260, 35)),
        Tower(QPoint(350, 35))
    };

    Enemy enemy[15]=//��ʼ��15ֻ��ͬ�ȼ�������ڻ���Բ����͹����������н�һ���Ż���Ŀǰ�ݶ�Ϊ15ֻ��
    {
        Enemy(QPoint(0,70),1),
        Enemy(QPoint(0,70),1),
        Enemy(QPoint(0,70),1),
        Enemy(QPoint(0,70),1),
        Enemy(QPoint(0,70),1),
        Enemy(QPoint(0,70),1),
        Enemy(QPoint(0,70),1),
        Enemy(QPoint(0,60),2),
        Enemy(QPoint(0,60),2),
        Enemy(QPoint(0,60),2),
        Enemy(QPoint(0,60),2),
        Enemy(QPoint(0,60),2),
        Enemy(QPoint(0,60),2),
        Enemy(QPoint(0,40),3),
        Enemy(QPoint(0,40),3)
    };
};

#endif // MAINWINDOW_H
