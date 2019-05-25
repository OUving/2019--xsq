#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    printf("hello world!\n");
    MainWindow w;
    w.setWindowTitle("立式焊机控制系统");
    w.show();

    return a.exec();
}
