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
    MyButton *bin = new MyButton(":/new/prefix1/picture/Button.png");//��ʼ��һ����ʼ��ť
    bin->setParent(this);
    bin->move(340,200);
    connect(bin,&QPushButton::clicked,this,[=](){//����lambda��ʽ��������л��ź�
        player->pause();//��ǰ���������ֹͣ
        this->close();//��ǰ����ر�
        MainWindow *scene = new MainWindow;//�½�һ��Mainwindow���沢��
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
