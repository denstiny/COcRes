#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //初始化
    b2 = new QPushButton("hello,qt",this);
    //b2->setText("hello,qt");
    //b2->show();
    b1.setParent(this);
    b1.setText("lao");
    b1.move(200,10);
}

MainWindow::~MainWindow()
{
}

