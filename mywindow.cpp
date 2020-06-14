#include "mywindow.h"
#include "ui_mywindow.h"
#include "QPaintEvent"
#include "QPainter"
#include "QPushButton"
#include "mainwindow.h"
#include "mybutton.h"
#include "QMediaPlayer"
Mywindow::Mywindow(QWidget *parent) ://��ʼ��һ����ʼ����
    QMainWindow(parent),
    ui(new Ui::Mywindow)
{
    ui->setupUi(this);
    QMediaPlayer *player = new QMediaPlayer;//���ſ�ʼ���������
    player->setMedia(QUrl("qrc:/new/prefix1/sounds/bgm0.mp3"));
    player->setVolume(30);
    player->play();
    MyButton *bin1 = new MyButton(":/new/prefix1/picture/Button1.png");//��ʼ��һ����ʼ��ť
    bin1->setParent(this);
    bin1->move(692,331);
    connect(bin1,&QPushButton::clicked,this,[=](){//����lambda��ʽ��������л��ź�
        player->pause();//��ǰ���������ֹͣ
        this->close();//��ǰ����ر�
        MainWindow *scene = new MainWindow;//�½�һ��Mainwindow���沢��
        scene->setspeed(1);
        scene->show();
    });
    MyButton *bin2 = new MyButton(":/new/prefix1/picture/Button2.png");//��ʼ��һ����ʼ��ť
    bin2->setParent(this);
    bin2->move(692,471);
    connect(bin2,&QPushButton::clicked,this,[=](){//����lambda��ʽ��������л��ź�
        player->pause();//��ǰ���������ֹͣ
        this->close();//��ǰ����ر�
        MainWindow *scene = new MainWindow;//�½�һ��Mainwindow���沢��
        scene->setspeed(2);
        scene->show();
    });
}
void Mywindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.drawPixmap(0,0,QPixmap(":/new/prefix1/picture/map0.png"));//���ƿ�ʼ���汳��
}
Mywindow::~Mywindow()
{
    delete ui;
}
