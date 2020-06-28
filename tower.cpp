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
    if(_live){//���Ʒ�����
        painter->drawPixmap(_pos,_picture);
        painter->setPen(Qt::white);
        painter->drawEllipse(centerPos(),_range,_range);//���ƹ�����Χ
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
    _strength=20;//������֮����
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
    _picture=QPixmap(":/new/prefix1/picture/tower.png");//�����в����ظ���δ����״̬
}
bool Tower::mostlevel(){
    return _mostlevel;
}
bool Tower::hastarget(){
    return _hastarget;
}
void Tower::attack(Enemy enemy[15]){//���Ĺ�������
    if(hastarget()==false){//�������û�й���Ŀ��
        for(int i=0;i<15;i++){//�������й���
            if(distance1(enemy[i].pos(),_pos)<=_range&&enemy[i].live()){//Ѱ�ұ������ĵ�һ���ڷ�����������Χ�ڵĴ�����
                _hastarget=true;
                _target=i;//����һ�����趨Ϊ�����Ĺ���Ŀ��
                break;//�����Թ���ı���
            }
        }
    }
    if(hastarget()&&enemy[_target].live()){//��ӵ�й���Ŀ���ҹ���Ŀ����������
        if(distance1(enemy[_target].pos(),_pos)<=_range&&enemy[_target].live()){//���Ŀ���ڹ�����Χ��
            shootbullet(enemy[_target]);//ִ���������
            enemy[_target].attacked(_strength);//�Թ�����й���
            if(_type==2)
                enemy[_target].inslow();
        }
        else if(distance1(enemy[_target].pos(),_pos)>_range)//�������Ŀ���뿪������Χ
            _hastarget=false;//ʧȥ��Ŀ��
    }
    if(hastarget()&&!enemy[_target].live()){//�������Ŀ������
        _hastarget=false;//ʧȥ��Ŀ��
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
