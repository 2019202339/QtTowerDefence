#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
class MyButton : public QPushButton//为了能够自定义按钮图案，重新写一个MyButton类，并以QPushButton作为他的父类
{
    Q_OBJECT
public:
    MyButton(QString pix);//MyButton的构造函数为他的图案地址

signals:

public slots:
};

#endif // MYBUTTON_H
