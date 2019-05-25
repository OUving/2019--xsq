#include "manual_adjust.h"
#include "ui_manual_adjust.h"

manual_adjust::manual_adjust(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::manual_adjust)
{
    ui->setupUi(this);
}

manual_adjust::~manual_adjust()
{
    delete ui;
}

void manual_adjust::on_pushButton_quit_clicked()
{
    emit manual_adjust_quit();
}

