#include "bullet.h"
#include "enemy.h"
#include "mainwindow.h"
#include <QPainter>
#include <QPropertyAnimation>

const QSize Bullet::ms_fixedSize(8, 8);

Bullet::Bullet(QPoint startPos, QPoint targetPoint,MainWindow *game,QPixmap sprite)
    : _startPos(startPos)
    , _targetPos(targetPoint)
    , _sprite(sprite)
    , _currentPos(startPos)
    , _game(game)

{
}

void Bullet::draw(QPainter *painter) const
{
    painter->drawPixmap(_currentPos, _sprite);
}

void Bullet::move()
{
    // 100ºÁÃëÄÚ»÷ÖÐµÐÈË
    static const int duration = 150;
    QPropertyAnimation *animation = new QPropertyAnimation(this, "_currentPos");
    animation->setDuration(duration);
    animation->setStartValue(_startPos);
    animation->setEndValue(_targetPos);
    connect(animation, SIGNAL(finished()), this, SLOT(hitTarget()));

    animation->start();
}

void Bullet::hitTarget()
{
    _game->removedBullet(this);
}

void Bullet::setCurrentPos(QPoint pos)
{
    _currentPos = pos;
}

QPoint Bullet::currentPos() const
{
    return _currentPos;
}
