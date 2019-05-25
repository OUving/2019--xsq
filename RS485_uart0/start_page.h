#ifndef START_PAGE_H
#define START_PAGE_H

#include <QWidget>

namespace Ui {
class start_page;
}

class start_page : public QWidget
{
    Q_OBJECT

public:
    explicit start_page(QWidget *parent = 0);
    ~start_page();


private:
    Ui::start_page *ui;
};

#endif // START_PAGE_H
