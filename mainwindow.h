#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<towerposition.h>
#include<tower.h>
#include<vector>
#include<QMouseEvent>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    vector<TowerPosition> _towerprositionlist;
    void loadtplist();
};

#endif // MAINWINDOW_H
