#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"QPainter"
#include<QList>
#include<towerposition.h>
#include<tower.h>


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
    for(int i=0;i<12;i++){
        painter.drawPixmap(point[i].x(),point[i].y(),QPixmap(":/new/prefix1/picture/towerposition.png"));
    }
    for(int i=0;i<12;i++){
        if(tower[i].live()&&tower[i].mostlevel()==false){
            painter.drawPixmap(pos[i].getPos(),QPixmap(":/new/prefix1/picture/tower.png"));
            painter.drawEllipse(pos[i].centerPos(),tower[i].range(),tower[i].range());
    }
        else if(tower[i].mostlevel()==true){
            painter.drawPixmap(pos[i].getPos(),QPixmap(":/new/prefix1/picture/tower2.png"));
            painter.drawEllipse(pos[i].centerPos(),tower[i].range(),tower[i].range());
        }

}
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint pressPos = event->pos();
    for(int i=0;i<12;i++){
        if(pos[i].containPoint(pressPos)&&pos[i].hastower()==false){
            tower[i].build();
            pos[i].settower();
            update();
        }
        else if(pos[i].containPoint(pressPos)&&pos[i].hastower()==true){
            tower[i].build1();
            update();
        }
    }

}


MainWindow::~MainWindow()
{
    delete ui;
}


