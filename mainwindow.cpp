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
#include<QBrush>
#include<money.h>
#include<QFont>
#include<QRectF>
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
    if(win){
        painter.drawPixmap(0,0,QPixmap(":/new/prefix1/picture/Win.png"));//����ʤ������
        return;//��������
    }
    if(lost){
        painter.drawPixmap(0,0,QPixmap(":/new/prefix1/picture/Lost.png"));//����ʧ�ܳ���
        return;//��������
    }
    painter.drawPixmap(0, 0, QPixmap(":/new/prefix1/picture/map.png"));//���Ƶ�ͼ����
    for(int i=0;i<15;i++){//���ݴ������͵Ǽ����������Ӧ�Ĺ���ͼ��
        enemy[i].draw(&painter);//���ù�����ƺ���
    }
    money.draw(&painter);//���ý�Ǯϵͳ���ƺ���
    for(int i=0;i<12;i++){
        tower[i].draw(&painter);//���÷��������ƺ���
    }
    painter.setPen(Qt::red);
    painter.drawText(800,475,"HP:"+QString::number(hp));//��������ֵ
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint pressPos = event->pos();
    for(int i=0;i<12;i++){
        if(pos[i].containPoint(pressPos)&&pos[i].hastower()==false&&money.canbuy(tower[i].price())){//�ж���������Ƿ�Ϊ��̨���жϸ���̨�Ƿ��Ѿ����÷����������޷��á���
            money=money-tower[i].price();//���н�Ҽ�ȥ���ļ۸�
            tower[i].build();//���������
            pos[i].settower();//����̨�������С����
            update();
        }
        else if(pos[i].containPoint(pressPos)&&pos[i].hastower()&&!tower[i].mostlevel()&&money.canbuy(tower[i].price())){//�ж���������Ƿ�Ϊ��̨���ж��Ƿ��Ѿ���ֹ�����������з��á���
            money=money-tower[i].price();//���н�Ҽ�ȥ���ļ۸�
            tower[i].build1();//����������
            update();//ˢ�»���
        }
        else if(pos[i].containPoint(pressPos)&&pos[i].hastower()&&tower[i].mostlevel()){//�ж���������Ƿ�Ϊ��̨���жϸô��Ƿ��Ѿ�ӵ����ߵȼ�������
            money=money+150;//���һ��������150���
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
                enemy[i].bite(hp);//�жϹ����Ƿ�ɹ���������
                enemy[i].death();//�жϹ����Ƿ��Ѿ�����
                if(!enemy[i].live()&&!enemy[i].hadreward()){//���������������Ѿ�������������δ��ȡ
                    money=money+enemy[i].reward();//���ϵͳ���ӹ��ｱ�����
                    enemy[i].setreward();//�ı�ù��ｱ��״̬
                }
            }
        }
        checkgame();
    }
    if(event->timerId()==4){
        for(int i=0;i<12;i++)//����ÿ������״̬
            if(tower[i].live())//��������
            tower[i].attack(enemy);//ִ�й�������
    }
    update();//ˢ�»���
}
void MainWindow::checkgame(){
    if(hp<=0){//����ֵС�ڵ���0��Ϸʧ��
        lost=true;
    }
    if(enemy[14].hadreward()&&hp>0){//���һֻ���ｱ��״̬��ɣ��������ֵ��Ȼ����0��Ϸ�ɹ�
        win=true;
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}


