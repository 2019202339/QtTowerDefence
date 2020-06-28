#include "wave.h"
#include "mainwindow.h"

Wave::Wave(MainWindow *game):_wave(1),_updata(false),_game(game)
{}
int Wave::getWave(){
    return _wave;
}
void Wave::drawWave(QPainter *painter){
    QFont font("Arial",20,QFont::Bold,true);
    painter->setFont(font);
    painter->setPen(Qt::yellow);//设置画笔颜色为黄色
    painter->drawText(520,30,"Wave:"+QString::number(_wave));
}
void Wave::newWave(Enemy enemy[]){
    if(enemy[14].hadreward()&&_wave<=_mostwave){
        for(int i=0;i<15;i++){
            if(i<6-_wave&&i%2!=0)
                enemy[i]=Enemy(QPoint(0,120),1,1);
            else if(i<6-_wave&&i%2==0)
                enemy[i]=Enemy(QPoint(0,120),2,1);
            else if(i<10-_wave&&i%2!=0)
                enemy[i]=Enemy(QPoint(0,140),3,2);
            else if(i<10-_wave&&i%2==0)
                enemy[i]=Enemy(QPoint(0,140),4,2);
            else
                enemy[i]=Enemy(QPoint(0,80),5,3);
        }
    _wave+=1;
    _updata=true;
    }

}
bool Wave::finishWave(){
    if(_wave>=_mostwave+1)
        return true;
    else
        return false;
}
bool Wave::inupdata(){
    return _updata;
}
void Wave::reupdata(){
    _updata=false;
}
int Wave::getmostwave(){
    return _mostwave;
}
void Wave::setmostwave(int mostwave){
    _mostwave=mostwave;
}
