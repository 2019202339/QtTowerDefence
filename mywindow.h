#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
namespace Ui {
class Mywindow;
}

class Mywindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit Mywindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    ~Mywindow();

private:
    Ui::Mywindow *ui;
};

#endif // MYWINDOW_H
