#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"QPainter"
#include<vector>
#include<towerposition.h>
#include<tower.h>


int a[12]={0};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
void MainWindow::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/new/prefix1/picture/map.png"));
    QPoint pos[] =
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
    for(int i=0;i<12;i++){
        painter.drawPixmap(pos[i].x(),pos[i].y(),QPixmap(":/new/prefix1/picture/towerposition.png"));
    }
    for(int i=0;i<12;i++){
        if(a[i]==1)
            painter.drawPixmap(pos[i].x(),pos[i].y(),QPixmap(":/new/prefix1/picture/tower.png"));
        else if(a[i]==2)
            painter.drawPixmap(pos[i].x(),pos[i].y(),QPixmap(":/new/prefix1/picture/tower2.png"));
    }
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint pressPos = event->pos();
    QPoint pos[] =
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
    for(int i=0;i<12;i++){
        TowerPosition p(pos[i]);
        if(p.containPoint(pressPos)&&!p.hastower()){
            a[i]=1;
            update();
        }
        else if(p.containPoint(pressPos)&&a[1]==1){
            a[i]=2;
            update();
        }
    }
}

void MainWindow::loadtplist(){
    QPoint pos[] =
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
    for(int i=0;i<12;i++)
    _towerprositionlist.push_back(TowerPosition(pos[i]));
}

MainWindow::~MainWindow()
{
    delete ui;
}


