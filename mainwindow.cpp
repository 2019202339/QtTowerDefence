#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"QPainter"
#include<QList>
#include<towerposition.h>
#include<tower.h>
#include<enemy.h>
#include<QTime>

int j=0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    startTimer(100);//�˶�״̬ˢ��ʱ�䣬����ֵtimerIdΪ2
    startTimer(3000);//�������ʱ����������ֵtimerIdΪ3
}
void MainWindow::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/new/prefix1/picture/map.png"));//���Ƶ�ͼ����
    for(int i=0;i<12;i++){
        painter.drawPixmap(point[i].x(),point[i].y(),QPixmap(":/new/prefix1/picture/towerposition.png"));//������̨
    }
    for(int i=0;i<12;i++){
        if(tower[i].live()&&tower[i].mostlevel()==false){//���Ʒ�����
            painter.drawPixmap(pos[i].getPos(),QPixmap(":/new/prefix1/picture/tower.png"));
            painter.drawEllipse(pos[i].centerPos(),tower[i].range(),tower[i].range());//���ƹ�����Χ
    }
        else if(tower[i].mostlevel()==true){//��������������
            painter.drawPixmap(pos[i].getPos(),QPixmap(":/new/prefix1/picture/tower2.png"));
            painter.drawEllipse(pos[i].centerPos(),tower[i].range(),tower[i].range());//���ƹ�����Χ
        }

    }
    for(int i=0;i<15;i++){//���ݴ������͵Ǽ����������Ӧ�Ĺ���ͼ��
        if(enemy[i].live()&&enemy[i].level()==1&&i%2==0)
            painter.drawPixmap(enemy[i].pos(), QPixmap(":/new/prefix1/picture/enemy1.png"));
        if(enemy[i].live()&&enemy[i].level()==1&&i%2!=0)
            painter.drawPixmap(enemy[i].pos(), QPixmap(":/new/prefix1/picture/enemy2.png"));
        if(enemy[i].live()&&enemy[i].level()==2&&i%2==0)
            painter.drawPixmap(enemy[i].pos(), QPixmap(":/new/prefix1/picture/enemy3.png"));
        if(enemy[i].live()&&enemy[i].level()==2&&i%2!=0)
            painter.drawPixmap(enemy[i].pos(), QPixmap(":/new/prefix1/picture/enemy4.png"));
        if(enemy[i].live()&&enemy[i].level()==3)
            painter.drawPixmap(enemy[i].pos(), QPixmap(":/new/prefix1/picture/enemy5.png"));
    }

}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint pressPos = event->pos();
    for(int i=0;i<12;i++){
        if(pos[i].containPoint(pressPos)&&pos[i].hastower()==false){//�ж���������Ƿ�Ϊ��̨���жϸ���̨�Ƿ��Ѿ����÷����������޷��á���
            tower[i].build();//���������
            pos[i].settower();//����̨�������С����
            update();
        }
        else if(pos[i].containPoint(pressPos)&&pos[i].hastower()==true){//�ж���������Ƿ�Ϊ��̨���ж��Ƿ��Ѿ���ֹ�����������з��á���
            tower[i].build1();//����������
            update();//ˢ�»���
        }
    }

}
void MainWindow::timerEvent(QTimerEvent *event)
{
    //�����ƶ�
    if(event->timerId()==3){
        enemy[j].birth();
        j+=1;
    }
    if(event->timerId()==2){
        for(int i=0;i<15;i++){//����ÿ������״̬
            if(enemy[i].live()){//�жϹ����Ƿ񼤻�
                enemy[i].move();//�����ƶ�����
                enemy[i].turn(turnpoint);//����ת�䶯��
                enemy[i].bite();//�жϹ����Ƿ�ɹ���������
                enemy[i].death();//�жϹ����Ƿ��Ѿ�����
            }
        }
    }
    update();//ˢ�»���

}


MainWindow::~MainWindow()
{
    delete ui;
}


