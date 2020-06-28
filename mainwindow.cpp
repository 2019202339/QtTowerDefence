#include "mainwindow.h"
#include "mywindow.h"
#include "ui_mainwindow.h"
#include"QPainter"
#include<QList>
#include<towerposition.h>
#include<tower.h>
#include<enemy.h>
#include<QTime>
#include<QDebug>
#include<mybutton.h>
#include<QMediaPlayer>
#include<QBrush>
#include<money.h>
#include<QFont>
#include<QRectF>
int j=0;
void MainWindow::setspeed(int speed){
    game_speed=speed;
    switch (game_speed) {
    case 1:
        wave.setmostwave(5);
        break;
    case 2:
        wave.setmostwave(10);
        break;
    }
}
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    startTimer(50);//运动状态刷新时间，返回值timerId为2
    startTimer(1500);//怪物产生时间间隔，返回值timerId为3
    startTimer(500);//防御塔攻击时间间隔，返回值timeId为4
    startTimer(25);//运动状态刷新时间，返回值timerId为5
    startTimer(750);//怪物产生时间间隔，返回值timerId为6
    startTimer(250);//防御塔攻击时间间隔，返回值timeId为7
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/new/prefix1/sounds/bgm.mp3"));
    player->setVolume(30);
    player->play();
}
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    if(win){
        painter.drawPixmap(0,0,QPixmap(":/new/prefix1/picture/Win.png"));//绘制胜利场景
        grade.getgrade(enemy,tower,money,hp,game_speed,true);
        grade.drawgrade(&painter);
        return;//结束绘制
    }
    if(lost){
        painter.drawPixmap(0,0,QPixmap(":/new/prefix1/picture/Lost.png"));//绘制失败场景
        grade.getgrade(enemy,tower,money,hp,game_speed,false);
        grade.drawgrade(&painter);
        return;//结束绘制
    }
    painter.drawPixmap(0, 0, QPixmap(":/new/prefix1/picture/map.png"));//绘制地图背景
    for(int i=0;i<15;i++){//根据存活情况和登记情况绘制相应的怪物图像
        enemy[i].draw(&painter);//调用怪物绘制函数
    }
    foreach (const Bullet *bullet, _bulletList)
        bullet->draw(&painter);
    money.draw(&painter);//调用金钱系统绘制函数
    wave.drawWave(&painter);//调用波数系统绘制函数
    for(int i=0;i<12;i++){
        tower[i].draw(&painter);//调用防御塔绘制函数
    }
    painter.setPen(Qt::red);
    painter.drawText(800,475,"HP:"+QString::number(hp));//绘制生命值
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint pressPos = event->pos();
    for(int i=0;i<12;i++){
        if(pos[i].containPoint(pressPos)&&pos[i].hastower()==false&&money.canbuy(tower[i].price())){//判断鼠标点击处是否为塔台并判断该塔台是否已经放置防御塔（“无放置”）
            if(event->button() == Qt::LeftButton)
                tower[i].settowertype(1);
            if(event->button() == Qt::RightButton)
                tower[i].settowertype(2);
            money=money-tower[i].price();//现有金币减去塔的价格
            tower[i].build();//建造防御塔
            pos[i].settower();//对塔台做“已有”标记
            update();
        }
        else if(pos[i].containPoint(pressPos)&&pos[i].hastower()&&!tower[i].mostlevel()&&money.canbuy(tower[i].price())){//判断鼠标点击处是否为塔台并判断是否已经防止防御塔（“有放置”）
            money=money-tower[i].price();//现有金币减去塔的价格
            tower[i].build1();//升级防御塔
            update();//刷新画面
        }
        else if(pos[i].containPoint(pressPos)&&pos[i].hastower()&&tower[i].mostlevel()){//判断鼠标点击处是否为塔台并判断该处是否已经拥有最高等级防御塔
            money=money+150;//拆除一个塔返回150金币
            tower[i].uninstall();//拆除防御塔
            pos[i].nosettower();//将塔台标记为无防御塔
            update();//刷新画面
        }
    }


}
void MainWindow::timerEvent(QTimerEvent *event)
{
    //怪物移动
    if(game_speed==1)
    {
        if(event->timerId()==3&&j<15&&!win&&!lost){
            enemy[j].birth();
            j+=1;
    }
    if(event->timerId()==2){
        wave.newWave(enemy);
        if(wave.inupdata()){
            j=0;
            wave.reupdata();
        }
        for(int i=0;i<15;i++){//遍历每个怪物状态
            if(enemy[i].live()){//判断怪物是否激活
                enemy[i].move();//怪物移动动作
                enemy[i].outslow();//检查怪物是否可以接触减速
                enemy[i].turn(turnpoint);//怪物转弯动作
                enemy[i].bite(hp);//判断怪物是否成功攻击基地
                enemy[i].death();//判断怪物是否已经死亡
                if(!enemy[i].live()&&!enemy[i].hadreward()){//奖励条件：怪物已经死亡，奖励尚未领取
                    money=money+enemy[i].reward();//金币系统增加怪物奖励金额
                    enemy[i].setreward();//改变该怪物奖励状态
                }
            }
        }
        checkgame();

    }
    if(event->timerId()==4){
        for(int i=0;i<12;i++)//遍历每个塔的状态
            if(tower[i].live())//如果塔存活
            tower[i].attack(enemy);//执行攻击函数
    }
    update();//刷新画面
    }
    if(game_speed==2){
        if(event->timerId()==5&&!win&&!lost){
            wave.newWave(enemy);
            if(wave.inupdata()){
                j=0;
                wave.reupdata();
            }
                    qDebug()<<wave.getmostwave()<<wave.getWave();
            for(int i=0;i<15;i++){//遍历每个怪物状态
                if(enemy[i].live()){//判断怪物是否激活
                    enemy[i].move();//怪物移动动作
                    enemy[i].turn(turnpoint);//怪物转弯动作
                    enemy[i].bite(hp);//判断怪物是否成功攻击基地
                    enemy[i].death();//判断怪物是否已经死亡
                    if(!enemy[i].live()&&!enemy[i].hadreward()){//奖励条件：怪物已经死亡，奖励尚未领取
                        money=money+enemy[i].reward();//金币系统增加怪物奖励金额
                        enemy[i].setreward();//改变该怪物奖励状态
                    }
                }
            }
            checkgame();
        }
        if(event->timerId()==6&&j<15&&!win&&!lost){
                enemy[j].birth();
                j+=1;
            }
            if(event->timerId()==7){
                for(int i=0;i<12;i++)//遍历每个塔的状态
                    if(tower[i].live())//如果塔存活
                    tower[i].attack(enemy);//执行攻击函数
            }
            update();//刷新画面
    }
}
void MainWindow::checkgame(){
    if(hp<=0){//生命值小于等于0游戏失败
        lost=true;
    }
    if(wave.finishWave()&&hp>0){//最后一只怪物奖励状态完成，玩家生命值依然大于0游戏成功
        win=true;
    }
}
void MainWindow::removedBullet(Bullet *bullet)
{
    Q_ASSERT(bullet);

    _bulletList.removeOne(bullet);
    delete bullet;
}

void MainWindow::addBullet(Bullet *bullet)
{
    Q_ASSERT(bullet);

    _bulletList.push_back(bullet);
}
int MainWindow::getspeed(){
    return game_speed;
}
MainWindow::~MainWindow()
{
    delete ui;
}


