#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer1 = new QTimer(this);
    timer1->start(1000);
    connect(timer1,SIGNAL(timeout()),this,SLOT(time_update()));

    ui->pushButton_startsys->setEnabled(false);
    ui->pushButton_stopsys->setEnabled(false);
    ui->pushButton_widget1->setEnabled(false);
    ui->pushButton_widget2->setEnabled(false);
    ui->pushButton_widget3->setEnabled(false);
    ui->pushButton_widget4->setEnabled(false);
    ui->pushButton_pre->setEnabled(false);
    ui->pushButton_next->setEnabled(false);
    ui->pushButton_startpage1->setEnabled(false);
    ui->pushButton_monitor->setEnabled(false);
    ui->pushButton_adjust->setEnabled(false);

    login_page = new login_window(this);
    start_page1 = new start_page(this);
    widget1_page = new widget1(this);
    widget2_page = new widget2(this);
    widget3_page = new widget3(this);
    widget4_page = new widget4(this);
    manual_adjust_page = new manual_adjust(this);


    connect(login_page,SIGNAL(loginsuccess()),this,SLOT(on_pushButton_startpage1_clicked()));
    connect(login_page,SIGNAL(close()),this,SLOT(on_pushButton_closepro_clicked()));
    connect(manual_adjust_page,SIGNAL(manual_adjust_quit()),this,SLOT(on_pushButton_startpage1_clicked()));


    ui->stackedWidget->addWidget(login_page);
    ui->stackedWidget->addWidget(start_page1);
    ui->stackedWidget->addWidget(widget1_page);
    ui->stackedWidget->addWidget(widget2_page);
    ui->stackedWidget->addWidget(widget3_page);
    ui->stackedWidget->addWidget(widget4_page);
    ui->stackedWidget->addWidget(manual_adjust_page);


    ui->stackedWidget->setCurrentWidget(login_page);
    startpage_index = ui->stackedWidget->currentIndex();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete myCom;
    delete timer1;
    delete timer2;
    delete start_page1;
    delete widget1_page;
    delete widget2_page;
    delete widget3_page;
    delete widget4_page;
    delete manual_adjust_page;
    delete login_page;

}


void MainWindow::on_pushButton_startpage1_clicked()
{
    ui->pushButton_startsys->setEnabled(true);
    ui->pushButton_startpage1->setEnabled(true);
    ui->pushButton_monitor->setEnabled(true);
    ui->pushButton_adjust->setEnabled(true);
    ui->pushButton_widget1->setEnabled(false);
    ui->pushButton_widget2->setEnabled(false);
    ui->pushButton_widget3->setEnabled(false);
    ui->pushButton_widget4->setEnabled(false);
    ui->pushButton_pre->setEnabled(false);
    ui->pushButton_next->setEnabled(false);

    ui->pushButton_widget1->setStyleSheet("background-color: rgb(255, 255, 255)");
    ui->pushButton_widget2->setStyleSheet("background-color: rgb(255, 255, 255)");
    ui->pushButton_widget3->setStyleSheet("background-color: rgb(255, 255, 255)");
    ui->pushButton_widget4->setStyleSheet("background-color: rgb(255, 255, 255)");
    ui->pushButton_startpage1->setStyleSheet("background-color: rgb(100, 100, 100)");
    ui->pushButton_monitor->setStyleSheet("background-color: rgb(255, 255, 255)");
    ui->pushButton_adjust->setStyleSheet("background-color: rgb(255, 255, 255)");

    ui->stackedWidget->setCurrentWidget(start_page1);
}

void MainWindow::on_pushButton_monitor_clicked()
{
    ui->pushButton_widget1->setEnabled(true);
    ui->pushButton_widget2->setEnabled(true);
    ui->pushButton_widget3->setEnabled(true);
    ui->pushButton_widget4->setEnabled(true);
    ui->pushButton_pre->setEnabled(true);
    ui->pushButton_next->setEnabled(true);
    ui->pushButton_startpage1->setStyleSheet("background-color: rgb(255, 255, 255)");
    ui->pushButton_adjust->setStyleSheet("background-color: rgb(255, 255, 255)");
    ui->pushButton_monitor->setStyleSheet("background-color: rgb(100, 100, 100)");
    on_pushButton_widget1_clicked();
}

void MainWindow::on_pushButton_adjust_clicked()
{
    ui->pushButton_startsys->setEnabled(true);
    ui->pushButton_startpage1->setEnabled(true);
    ui->pushButton_monitor->setEnabled(true);
    ui->pushButton_adjust->setEnabled(true);
    ui->pushButton_widget1->setEnabled(false);
    ui->pushButton_widget2->setEnabled(false);
    ui->pushButton_widget3->setEnabled(false);
    ui->pushButton_widget4->setEnabled(false);
    ui->pushButton_pre->setEnabled(false);
    ui->pushButton_next->setEnabled(false);

    ui->pushButton_widget1->setStyleSheet("background-color: rgb(255, 255, 255)");
    ui->pushButton_widget2->setStyleSheet("background-color: rgb(255, 255, 255)");
    ui->pushButton_widget3->setStyleSheet("background-color: rgb(255, 255, 255)");
    ui->pushButton_widget4->setStyleSheet("background-color: rgb(255, 255, 255)");
    ui->pushButton_adjust->setStyleSheet("background-color: rgb(100, 100, 100)");
    ui->pushButton_startpage1->setStyleSheet("background-color: rgb(255, 255, 255)");
    ui->pushButton_monitor->setStyleSheet("background-color: rgb(255, 255, 255)");

    ui->stackedWidget->setCurrentWidget(manual_adjust_page);
}

void MainWindow::on_pushButton_widget1_clicked()
{
    ui->stackedWidget->setCurrentWidget(widget1_page);
    ui->pushButton_widget1->setStyleSheet("background-color: rgb(100, 255, 100)");
    ui->pushButton_widget2->setStyleSheet("background-color: rgb(255, 255, 255)");
    ui->pushButton_widget3->setStyleSheet("background-color: rgb(255, 255, 255)");
    ui->pushButton_widget4->setStyleSheet("background-color: rgb(255, 255, 255)");

}

void MainWindow::on_pushButton_widget2_clicked()
{
    ui->stackedWidget->setCurrentWidget(widget2_page);
    ui->pushButton_widget1->setStyleSheet("background-color: rgb(255, 255, 255)");
    ui->pushButton_widget2->setStyleSheet("background-color: rgb(100, 255, 100)");
    ui->pushButton_widget3->setStyleSheet("background-color: rgb(255, 255, 255)");
    ui->pushButton_widget4->setStyleSheet("background-color: rgb(255, 255, 255)");

}

void MainWindow::on_pushButton_widget3_clicked()
{
    ui->stackedWidget->setCurrentWidget(widget3_page);
    ui->pushButton_widget1->setStyleSheet("background-color: rgb(255, 255, 255)");
    ui->pushButton_widget2->setStyleSheet("background-color: rgb(255, 255, 255)");
    ui->pushButton_widget3->setStyleSheet("background-color: rgb(100, 255, 100)");
    ui->pushButton_widget4->setStyleSheet("background-color: rgb(255, 255, 255)");

}

void MainWindow::on_pushButton_widget4_clicked()
{
    ui->stackedWidget->setCurrentWidget(widget4_page);
    ui->pushButton_widget1->setStyleSheet("background-color: rgb(255, 255, 255)");
    ui->pushButton_widget2->setStyleSheet("background-color: rgb(255, 255, 255)");
    ui->pushButton_widget3->setStyleSheet("background-color: rgb(255, 255, 255)");
    ui->pushButton_widget4->setStyleSheet("background-color: rgb(100, 255, 100)");

}


void MainWindow::on_pushButton_next_clicked()
{

    if (ui->stackedWidget->currentIndex() == startpage_index + 2)
        on_pushButton_widget2_clicked();
    else if (ui->stackedWidget->currentIndex() == startpage_index + 3)
        on_pushButton_widget3_clicked();
    else if (ui->stackedWidget->currentIndex() == startpage_index + 4)
        on_pushButton_widget4_clicked();


}

void MainWindow::on_pushButton_pre_clicked()
{

    if(ui->stackedWidget->currentIndex() > startpage_index + 2)
    {
        if (ui->stackedWidget->currentIndex() ==  ui->stackedWidget->count() - 2)
            on_pushButton_widget3_clicked();
        else if (ui->stackedWidget->currentIndex() == ui->stackedWidget->count() - 3)
            on_pushButton_widget2_clicked();
        else if (ui->stackedWidget->currentIndex() == ui->stackedWidget->count() - 4)
            on_pushButton_widget1_clicked();

    }

}


void MainWindow::time_update()
{
    QDateTime curDateTime = QDateTime::currentDateTime();
    ui->dateTimeEdit->setDateTime(curDateTime);
}

void MainWindow::on_pushButton_startsys_clicked()
{
    myCom = new Posix_QextSerialPort("/dev/ttyPS1",QextSerialBase::Polling);
    myCom ->open(QIODevice::ReadWrite); //以读写方式打开串口
    myCom->setBaudRate(BAUD115200); //波特率设置，我们设置为115200
    myCom->setDataBits(DATA_8); //数据位设置，我们设置为8位数据位
    myCom->setParity(PAR_NONE); //奇偶校验设置，我们设置为无校验
    myCom->setStopBits(STOP_1); //停止位设置，我们设置为1位停止位
    myCom->setFlowControl(FLOW_OFF); //数据流控制设置，我们设置为无数据流控制
    myCom->setTimeout(1);

    if(myCom->isOpen())
    {
        ui->pushButton_stopsys->setEnabled(true);
        ui->pushButton_startsys->setStyleSheet("background-color: rgb(0, 255, 0)");
    }
    else
        QMessageBox::information(NULL, "提示", "启动系统失败，请重新启动", QMessageBox::Yes, QMessageBox::Yes);

    timer2 = new QTimer(this);
    timer2->start(2000);
    connect(timer2,SIGNAL(timeout()),this,SLOT(readCom()));
}

void MainWindow::on_pushButton_stopsys_clicked()
{

}
void MainWindow::on_pushButton_closepro_clicked()
{
//    qDebug() << __LINE__ << "myCom->isOpen() = " << myCom->isOpen() << endl ;
    if(myCom->isOpen())
    {
         myCom->close();
    }
//        qDebug() << __LINE__ << "myCom->isOpen() = " << myCom->isOpen() << endl ;
    this->close();
}

void MainWindow::readCom()
{
    timer2->stop();
    if(myCom->isOpen())
    {
        qDebug() << __LINE__ << ",myCom->isOpen = " << myCom->isOpen() << endl;
        qDebug() << __LINE__ << ",myCom->bytesAvailable = " << myCom->bytesAvailable() << endl;

           if(myCom->bytesAvailable() >= 8)
           {
                qDebug() << __LINE__ << endl;
                QByteArray temp;
                temp = myCom->readAll();

                 qDebug() << __LINE__ << "temp.size() = " << temp.size() << endl;

                 qDebug()<< "line = " << __LINE__ << endl;
                if(!temp.isEmpty())
                 {
                    ui->textBrowser_recv->clear();
                      temp=temp.toHex();
                     ui->textBrowser_recv->insertPlainText(temp);
                  }

    }
            timer2->start(2000);
}
}



