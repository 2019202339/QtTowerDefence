#include "mainwindow.h"
#include <QApplication>
#include "mywindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Mywindow *m = new Mywindow;
    m->show();

    return a.exec();
}
