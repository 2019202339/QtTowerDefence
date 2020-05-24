#include "mainwindow.h"
#include <QApplication>
#include "mywindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Mywindow m;
    m.show();

    return a.exec();
}
