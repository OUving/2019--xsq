#ifndef LOGIN_WINDOW_H
#define LOGIN_WINDOW_H

#include <QWidget>

namespace Ui {
class login_window;
}

class login_window : public QWidget
{
    Q_OBJECT

public:
    explicit login_window(QWidget *parent = 0);
    ~login_window();

signals:
    void loginsuccess();

    void close();

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_close_clicked();

    void on_lineEdit_password_returnPressed();

private:
    Ui::login_window *ui;
};

#endif // LOGIN_WINDOW_H
