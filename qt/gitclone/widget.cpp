#include "widget.h"
#include "QMessageBox"
#include "qprocess.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 链接信号与槽
    connect(ui->lineEdit,SIGNAL(returnPressed()),this,SLOT(on_pushButton_clicked()));
}

Widget::~Widget()
{
    delete ui;
}

//  clone 命令
void Widget::on_pushButton_clicked()
{
    // 获取lineEdit 仓库链接
    QString url = ui->lineEdit->text();
    // 创建 Qprocess 对象
    QProcess * myProcess = new QProcess(this) ;
    // 启动
    QProcess *cmd = new QProcess(this);
    QString cmd_shell = "Cgit " + url;
    connect(cmd , SIGNAL(readyReadStandardOutput()) , this , SLOT(on_readoutput()));
    connect(cmd , SIGNAL(readyReadStandardError()) , this , SLOT(on_readerror()));
    cmd->start(cmd_shell);
}


