#ifndef BULLET_H
#define BULLET_H

#include <QPoint>
#include <QSize>
#include <QPixmap>
#include <QObject>

class QPainter;
class Enemy;
class MainWindow;

class Bullet : QObject
{
    Q_OBJECT
    Q_PROPERTY(QPoint _currentPos READ currentPos WRITE setCurrentPos)

public:
    Bullet(QPoint startPos, QPoint targetPoint,MainWindow *game,QPixmap sprite);

    void draw(QPainter *painter) const;
    void move();
    void setCurrentPos(QPoint pos);
    QPoint currentPos() const;

private slots:
    void hitTarget();

private:
    const QPoint	_startPos;
    const QPoint	_targetPos;
    const QPixmap	_sprite;
    QPoint			_currentPos;
    MainWindow *	_game;

    static const QSize ms_fixedSize;
};

#endif // BULLET_H
