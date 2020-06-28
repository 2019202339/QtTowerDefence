#ifndef WAVE_H
#define WAVE_H
#include "enemy.h"
#include "QPainter"
class MainWindow;
class Wave
{
public:
    Wave(MainWindow *game);
    int getWave();
    void drawWave(QPainter *painter);
    void newWave(Enemy enemy[15]);
    bool finishWave();
    void reupdata();
    bool inupdata();
    void setmostwave(int mostwave);
    int getmostwave();
private:
    int _wave;
    bool _updata;
    MainWindow *_game;
    int _mostwave;
};

#endif // WAVE_H
