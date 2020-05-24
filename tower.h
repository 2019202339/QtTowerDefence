#ifndef TOWER_H
#define TOWER_H
#include <QPoint>
#include <QSize>
#include <QPixmap>
class QPainter;
class MainWindow;
class Enemy;
class Tower
{
public:
    Tower(QPoint p);//��λ�ö������г�ʼ��
    int range();//�������Ĺ�����Χ
    bool live();//�ж����Ĵ���
    bool mostlevel();//�ж����ĵȼ�
    void build();//�ڿ�����λ������
    void build1();//����Ѿ����ڵ�������
    void uninstall();//�������в��
    bool hastarget();//�ж����Ƿ��Ѿ�ӵ�й�������
    void attack(Enemy enemy[15]);//���Ĺ�������



protected:
    QPoint _pos;//����λ��
    int _range;//���Ĺ�����Χ
    int _strength;//�����˺�ֵ
    int _rate;//���Ĺ���Ƶ��
    bool _live;//���Ƿ����
    bool _mostlevel;//���Ƿ�������߼�
    bool _hastarget;//���Ƿ�ӵ�й�������
    int _target;//���Ĺ���Ŀ��

};

#endif // TOWER_H
