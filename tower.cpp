#include "tower.h"
#include "mainwindow.h"
#include <QPainter>
#include <enemy.h>
#include <QMediaPlayer>
#include<QSize>

QMediaPlayer *player2 = new QMediaPlayer;
double distance1(QPoint m,QPoint n){
    return sqrt((m.x()-n.x())*(m.x()-n.x())+(m.y()-n.y())*(m.y()-n.y()));
}
Tower::Tower(const QPoint a,MainWindow *game):
    _pos(a),_type(0),_range(120),_strength(10),_rate(10),_live(false),_mostlevel(false),_hastarget(false),_target(-1),_price(100),_game(game)
{}
void Tower::draw(QPainter *painter){
    if(_live){//绘制防御塔
        painter->drawPixmap(_pos,_picture);
        painter->setPen(Qt::white);
        painter->drawEllipse(centerPos(),_range,_range);//绘制攻击范围
}
}
void Tower::settowertype(int type){
    _type=type;
    if(type==1)
        _price=100;
    if(type==2)
        _price=150;
}
const QPoint Tower::centerPos() const{
    QPoint halfpoint(44,44);
    return _pos+halfpoint;
}

int Tower::range(){
    return _range;
}
void Tower::build(){    
    player2->setMedia(QUrl("qrc:/new/prefix1/sounds/tower1birth.mp3"));
    player2->setVolume(30);
    _live=true;
    if(_type==1)
        _picture=QPixmap(":/new/prefix1/picture/tower.png");
    if(_type==2)
        _picture=QPixmap(":/new/prefix1/picture/tower3.png");
    player2->play();
}
bool Tower::live(){
    return _live;
}
void Tower::build1(){
    player2->setMedia(QUrl("qrc:/new/prefix1/sounds/tower1birth.mp3"));
    player2->setVolume(30);
    _live=true;
    _mostlevel=true;
    _range=180;
    _strength=20;//参数随之升级
    if(_type==1)
        _picture=QPixmap(":/new/prefix1/picture/tower2.png");
    if(_type==2)
        _picture=QPixmap(":/new/prefix1/picture/tower4.png");
    player2->play();
}
void Tower::uninstall(){
    player2->setMedia(QUrl("qrc:/new/prefix1/sounds/crash.mp3"));
    player2->setVolume(30);
    player2->play();
    _mostlevel=false;
    _live=false;
    _type=0;
    _range=120;
    _strength=50;
    _picture=QPixmap(":/new/prefix1/picture/tower.png");//将所有参数回复到未激活状态
}
bool Tower::mostlevel(){
    return _mostlevel;
}
bool Tower::hastarget(){
    return _hastarget;
}
void Tower::attack(Enemy enemy[15]){//塔的攻击函数
    if(hastarget()==false){//如果防御没有攻击目标
        for(int i=0;i<15;i++){//遍历所有怪物
            if(distance1(enemy[i].pos(),_pos)<=_range&&enemy[i].live()){//寻找遍历到的第一个在防御塔攻击范围内的存活怪物
                _hastarget=true;
                _target=i;//将这一怪物设定为该塔的攻击目标
                break;//结束对怪物的遍历
            }
        }
    }
    if(hastarget()&&enemy[_target].live()){//在拥有攻击目标且攻击目标存活的情况下
        if(distance1(enemy[_target].pos(),_pos)<=_range&&enemy[_target].live()){//如果目标在攻击范围内
            shootbullet(enemy[_target]);//执行射击动作
            enemy[_target].attacked(_strength);//对怪物进行攻击
            if(_type==2)
                enemy[_target].inslow();
        }
        else if(distance1(enemy[_target].pos(),_pos)>_range)//如果攻击目标离开攻击范围
            _hastarget=false;//失去该目标
    }
    if(hastarget()&&!enemy[_target].live()){//如果攻击目标死亡
        _hastarget=false;//失去该目标
    }
}
int Tower::gettarget(){
    return _target;
}
int Tower::price(){
    return _price;
}
void Tower::shootbullet(Enemy enemy){
    if(_type==1){
        Bullet *bullet = new Bullet(_pos, enemy.pos(), _game,QPixmap(":/new/prefix1/picture/bullet.png"));
        bullet->move();
        _game->addBullet(bullet);
    }
    if(_type==2){
        Bullet *bullet = new Bullet(_pos, enemy.pos(), _game,QPixmap(":/new/prefix1/picture/bullet1.png"));
        bullet->move();
        _game->addBullet(bullet);
    }
}
