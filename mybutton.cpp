#include "mybutton.h"
#include "QPixmap"
#include "QSize"
MyButton::MyButton(QString pix){
    QPixmap pixmap(pix);
    this->setFixedSize(QSize(pixmap.width(),pixmap.height()));
    this->setStyleSheet("QPushButton{border:Opx}");
    this->setIcon(pixmap);
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));
}

