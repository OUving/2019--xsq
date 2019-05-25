#include "login_window.h"
#include "ui_login_window.h"
#include <QMessageBox>

login_window::login_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login_window)
{
    ui->setupUi(this);
}

login_window::~login_window()
{
    delete ui;
}

void login_window::on_pushButton_login_clicked()
{
    if(ui->lineEdit_username->text() == "root"&&ui->lineEdit_password->text() == "root")
        emit loginsuccess();
    else
        QMessageBox::critical(NULL, "错误警告", "您输入的用户名或密码有误，请重新输入", QMessageBox::Yes, QMessageBox::Yes);
}

void login_window::on_pushButton_close_clicked()
{
    emit close();
}

void login_window::on_lineEdit_password_returnPressed()
{
    emit ui->pushButton_login->click();
}
