#ifndef TOWER_H
#define TOWER_H
#include <QPoint>
#include <QSize>
#include <QPixmap>
class QPainter;
class MainWindow;

class Tower
{
public:
    Tower(QPoint p);//��λ�ö������г�ʼ��
    int range();//�������Ĺ�����Χ
    bool live();//�ж����Ĵ���
    bool mostlevel();//�ж����ĵȼ�
    void build();//�ڿ�����λ������
    void build1();//����Ѿ����ڵ�������


protected:
    QPoint _pos;//����λ��
    int _range;//���Ĺ�����Χ
    int _strength;//�����˺�ֵ
    int _rate;//���Ĺ���Ƶ��
    bool _live;//���Ƿ����
    bool _mostlevel;//���Ƿ�������߼�
};

#endif // TOWER_H
