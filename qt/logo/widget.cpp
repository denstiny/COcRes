#include "widget.h"
#include "ui_widget.h"
#include "QPushButton"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton *button = new QPushButton;
    button->setParent(this);
    button->setText("的吗西亚"); // 设置按钮名称
    button->move(109,190); // 设置按钮位置
    setWindowTitle("QT");
}

Widget::~Widget()
{
    delete ui;
}


// 呈现窗体部件
void Widget::ShowFrom() {

}
