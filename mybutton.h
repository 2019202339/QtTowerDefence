#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
class MyButton : public QPushButton//Ϊ���ܹ��Զ��尴ťͼ��������дһ��MyButton�࣬����QPushButton��Ϊ���ĸ���
{
    Q_OBJECT
public:
    MyButton(QString pix);//MyButton�Ĺ��캯��Ϊ����ͼ����ַ

signals:

public slots:
};

#endif // MYBUTTON_H
