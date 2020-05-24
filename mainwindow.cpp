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
    startTimer(100);//运动状态刷新时间，返回值timerId为2
    startTimer(3000);//怪物产生时间间隔，返回值timerId为3
    startTimer(1000);//防御塔攻击时间间隔，返回值timeId为4
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/new/prefix1/sounds/bgm.mp3"));
    player->setVolume(30);
    player->play();
}
void MainWindow::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/new/prefix1/picture/map.png"));//绘制地图背景
    for(int i=0;i<12;i++){
        painter.drawPixmap(point[i].x(),point[i].y(),QPixmap(":/new/prefix1/picture/towerposition.png"));//绘制塔台
    }
    for(int i=0;i<12;i++){
        if(tower[i].live()&&tower[i].mostlevel()==false){//绘制防御塔
            painter.drawPixmap(pos[i].getPos(),QPixmap(":/new/prefix1/picture/tower.png"));
            painter.drawEllipse(pos[i].centerPos(),tower[i].range(),tower[i].range());//绘制攻击范围
    }
        else if(tower[i].mostlevel()==true){//绘制升级防御塔
            painter.drawPixmap(pos[i].getPos(),QPixmap(":/new/prefix1/picture/tower2.png"));
            painter.drawEllipse(pos[i].centerPos(),tower[i].range(),tower[i].range());//绘制攻击范围
        }

    }
    for(int i=0;i<15;i++){//根据存活情况和登记情况绘制相应的怪物图像
        if(enemy[i].live()&&enemy[i].level()==1&&i%2==0){
            painter.setPen(Qt::red);
            painter.drawRect(enemy[i].pos().x(),enemy[i].pos().y(),50,1);
            painter.setPen(Qt::green);
            painter.drawRect(enemy[i].pos().x(),enemy[i].pos().y(),50*(enemy[i].hp()/100),1);//利用矩形组合的方法绘制血槽
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
        if(pos[i].containPoint(pressPos)&&pos[i].hastower()==false){//判断鼠标点击处是否为塔台并判断该塔台是否已经放置防御塔（“无放置”）
            tower[i].build();//建造防御塔
            pos[i].settower();//对塔台做“已有”标记
            update();
        }
        else if(pos[i].containPoint(pressPos)&&pos[i].hastower()&&!tower[i].mostlevel()){//判断鼠标点击处是否为塔台并判断是否已经防止防御塔（“有放置”）
            tower[i].build1();//升级防御塔
            update();//刷新画面
        }
        else if(pos[i].containPoint(pressPos)&&pos[i].hastower()&&tower[i].mostlevel()){//判断鼠标点击处是否为塔台并判断该处是否已经拥有最高等级防御塔
            tower[i].uninstall();//拆除防御塔
            pos[i].nosettower();//将塔台标记为无防御塔
            update();//刷新画面
        }
    }

}
void MainWindow::timerEvent(QTimerEvent *event)
{
    //怪物移动
    if(event->timerId()==3){
        enemy[j].birth();
        j+=1;
    }
    if(event->timerId()==2){
        for(int i=0;i<15;i++){//遍历每个怪物状态
            if(enemy[i].live()){//判断怪物是否激活
                enemy[i].move();//怪物移动动作
                enemy[i].turn(turnpoint);//怪物转弯动作
                enemy[i].bite();//判断怪物是否成功攻击基地
                enemy[i].death();//判断怪物是否已经死亡
            }
        }
    }
    if(event->timerId()==4){
        for(int i=0;i<12;i++)//遍历每个塔的状态
            if(tower[i].live())//如果塔存活
            tower[i].attack(enemy);//执行攻击函数
    }
    update();//刷新画面

}


MainWindow::~MainWindow()
{
    delete ui;
}


