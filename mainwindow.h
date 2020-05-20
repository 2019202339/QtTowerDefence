#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<towerposition.h>
#include<tower.h>
#include<QList>
#include<QMouseEvent>
#include<QTimerEvent>

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
    void timerEvent(QTimerEvent *);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPoint point[12] =//初始化12个可放置点
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
    TowerPosition pos[12] =//初始化12个塔位
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
    Tower tower[12] =//初始化12座塔
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
};

#endif // MAINWINDOW_H
