#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"QPainter"
#include<QList>
#include<towerposition.h>
#include<tower.h>
#include<enemy.h>
#include<QTime>
#include<QDebug>
#include<QMediaPlayer>
int j=0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    startTimer(100);//�˶�״̬ˢ��ʱ�䣬����ֵtimerIdΪ2
    startTimer(3000);//�������ʱ����������ֵtimerIdΪ3
    startTimer(1000);//����������ʱ����������ֵtimeIdΪ4
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/new/prefix1/sounds/bgm.mp3"));
    player->setVolume(30);
    player->play();
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
        if(enemy[i].live()&&enemy[i].level()==1&&i%2==0){
            painter.setPen(Qt::red);
            painter.drawRect(enemy[i].pos().x(),enemy[i].pos().y(),50,1);
            painter.setPen(Qt::green);
            painter.drawRect(enemy[i].pos().x(),enemy[i].pos().y(),50*(enemy[i].hp()/100),1);//���þ�����ϵķ�������Ѫ��
            painter.drawPixmap(enemy[i].pos(), QPixmap(":/new/prefix1/picture/enemy1.png"));}
        if(enemy[i].live()&&enemy[i].level()==1&&i%2!=0){
            painter.setPen(Qt::red);
            painter.drawRect(enemy[i].pos().x(),enemy[i].pos().y(),50,1);
            painter.setPen(Qt::green);
            painter.drawRect(enemy[i].pos().x(),enemy[i].pos().y(),50*(enemy[i].hp()/100),1);
            painter.drawPixmap(enemy[i].pos(), QPixmap(":/new/prefix1/picture/enemy2.png"));}
        if(enemy[i].live()&&enemy[i].level()==2&&i%2==0){
            painter.setPen(Qt::red);
            painter.drawRect(enemy[i].pos().x(),enemy[i].pos().y(),50,1);
            painter.setPen(Qt::green);
            painter.drawRect(enemy[i].pos().x(),enemy[i].pos().y(),50*(enemy[i].hp()/200),1);
            painter.drawPixmap(enemy[i].pos(), QPixmap(":/new/prefix1/picture/enemy3.png"));}
        if(enemy[i].live()&&enemy[i].level()==2&&i%2!=0){
            painter.setPen(Qt::red);
            painter.drawRect(enemy[i].pos().x(),enemy[i].pos().y(),50,1);
            painter.setPen(Qt::green);
            painter.drawRect(enemy[i].pos().x(),enemy[i].pos().y(),50*(enemy[i].hp()/200),1);
            painter.drawPixmap(enemy[i].pos(), QPixmap(":/new/prefix1/picture/enemy4.png"));}
        if(enemy[i].live()&&enemy[i].level()==3){
            painter.setPen(Qt::red);
            painter.drawRect(enemy[i].pos().x(),enemy[i].pos().y(),50,1);
            painter.setPen(Qt::green);
            painter.drawRect(enemy[i].pos().x(),enemy[i].pos().y(),50*(enemy[i].hp()/300),1);
            painter.drawPixmap(enemy[i].pos(), QPixmap(":/new/prefix1/picture/enemy5.png"));}
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
        else if(pos[i].containPoint(pressPos)&&pos[i].hastower()&&!tower[i].mostlevel()){//�ж���������Ƿ�Ϊ��̨���ж��Ƿ��Ѿ���ֹ�����������з��á���
            tower[i].build1();//����������
            update();//ˢ�»���
        }
        else if(pos[i].containPoint(pressPos)&&pos[i].hastower()&&tower[i].mostlevel()){//�ж���������Ƿ�Ϊ��̨���жϸô��Ƿ��Ѿ�ӵ����ߵȼ�������
            tower[i].uninstall();//���������
            pos[i].nosettower();//����̨���Ϊ�޷�����
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
    if(event->timerId()==4){
        for(int i=0;i<12;i++)//����ÿ������״̬
            if(tower[i].live())//��������
            tower[i].attack(enemy);//ִ�й�������
    }
    update();//ˢ�»���

}


MainWindow::~MainWindow()
{
    delete ui;
}


