#include "tower.h"
#include "mainwindow.h"
#include <QPainter>
#include <enemy.h>
#include <QMediaPlayer>
QMediaPlayer *player2 = new QMediaPlayer;
double distance1(QPoint m,QPoint n){
    return sqrt((m.x()-n.x())*(m.x()-n.x())+(m.y()-n.y())*(m.y()-n.y()));
}
Tower::Tower(const QPoint a):
    _pos(a),_range(60),_strength(10),_rate(10),_live(false),_mostlevel(false),_hastarget(false),_target(-1)
{}
int Tower::range(){
    return _range;
}
void Tower::build(){    
    player2->setMedia(QUrl("qrc:/new/prefix1/sounds/tower1birth.mp3"));
    player2->setVolume(30);
    _live=true;
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
    _range=90;
    _strength=20;//������֮����
    player2->play();
}
void Tower::uninstall(){
    player2->setMedia(QUrl("qrc:/new/prefix1/sounds/crash.mp3"));
    player2->setVolume(30);
    player2->play();
    _mostlevel=false;
    _live=false;
    _range=60;
    _strength=50;//�����в����ظ���δ����״̬
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
            enemy[_target].attacked(_strength);//�Թ�����й���
        }
        else if(distance1(enemy[_target].pos(),_pos)>_range)//�������Ŀ���뿪������Χ
            _hastarget=false;//ʧȥ��Ŀ��
    }
    if(hastarget()&&!enemy[_target].live()){//�������Ŀ������
        _hastarget=false;//ʧȥ��Ŀ��
    }
}
