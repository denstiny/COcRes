#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);  // 初始化框架
    MainWindow w;  // 定义窗口框架

    // 用户代码


    w.show();  // 显示窗口
    return a.exec();
}
