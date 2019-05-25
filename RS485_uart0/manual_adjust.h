#ifndef MANUAL_ADJUST_H
#define MANUAL_ADJUST_H

#include <QWidget>

namespace Ui {
class manual_adjust;
}

class manual_adjust : public QWidget
{
    Q_OBJECT

public:
    explicit manual_adjust(QWidget *parent = 0);
    ~manual_adjust();

signals:
    void manual_adjust_quit();

private slots:
    void on_pushButton_quit_clicked();


private:
    Ui::manual_adjust *ui;
};

#endif // MANUAL_ADJUST_H
