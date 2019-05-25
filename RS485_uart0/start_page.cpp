#include "start_page.h"
#include "ui_start_page.h"

start_page::start_page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::start_page)
{
    ui->setupUi(this);
}

start_page::~start_page()
{
    delete ui;
}
