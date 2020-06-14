#include "mywindow.h"
#include "ui_mywindow.h"
#include "QPaintEvent"
#include "QPainter"
#include "QPushButton"
#include "mainwindow.h"
#include "mybutton.h"
#include "QMediaPlayer"
Mywindow::Mywindow(QWidget *parent) ://初始化一个开始界面
    QMainWindow(parent),
    ui(new Ui::Mywindow)
{
    ui->setupUi(this);
    QMediaPlayer *player = new QMediaPlayer;//播放开始界面的音乐
    player->setMedia(QUrl("qrc:/new/prefix1/sounds/bgm0.mp3"));
    player->setVolume(30);
    player->play();
    MyButton *bin1 = new MyButton(":/new/prefix1/picture/Button1.png");//初始化一个开始按钮
    bin1->setParent(this);
    bin1->move(692,331);
    connect(bin1,&QPushButton::clicked,this,[=](){//利用lambda公式传输界面切换信号
        player->pause();//当前界面的音乐停止
        this->close();//当前界面关闭
        MainWindow *scene = new MainWindow;//新建一个Mainwindow界面并打开
        scene->setspeed(1);
        scene->show();
    });
    MyButton *bin2 = new MyButton(":/new/prefix1/picture/Button2.png");//初始化一个开始按钮
    bin2->setParent(this);
    bin2->move(692,471);
    connect(bin2,&QPushButton::clicked,this,[=](){//利用lambda公式传输界面切换信号
        player->pause();//当前界面的音乐停止
        this->close();//当前界面关闭
        MainWindow *scene = new MainWindow;//新建一个Mainwindow界面并打开
        scene->setspeed(2);
        scene->show();
    });
}
void Mywindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.drawPixmap(0,0,QPixmap(":/new/prefix1/picture/map0.png"));//绘制开始界面背景
}
Mywindow::~Mywindow()
{
    delete ui;
}
