#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"posix_qextserialport.h"
#include <QTimer>
#include "start_page.h"
#include "widget1.h"
#include "widget2.h"
#include "widget3.h"
#include "widget4.h"
#include "login_window.h"
#include "manual_adjust.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0); //
    ~MainWindow();

    void init();

private slots:

    void time_update();

    void readCom();

    void on_pushButton_startsys_clicked();

    void on_pushButton_stopsys_clicked();

    void on_pushButton_closepro_clicked();

    void on_pushButton_widget1_clicked();

    void on_pushButton_widget2_clicked();

    void on_pushButton_widget3_clicked();

    void on_pushButton_widget4_clicked();

    void on_pushButton_next_clicked();

    void on_pushButton_pre_clicked();

    void on_pushButton_startpage1_clicked();


    void on_pushButton_monitor_clicked();

    void on_pushButton_adjust_clicked();



private:
    Ui::MainWindow *ui;
    start_page *start_page1;
    widget1 *widget1_page;
    widget2 *widget2_page;
    widget3 *widget3_page;
    widget4 *widget4_page;
    login_window *login_page;
    manual_adjust *manual_adjust_page;
    Posix_QextSerialPort *myCom;
    QTimer *timer1,*timer2;
    int startpage_index;


};

#endif // MAINWINDOW_H
