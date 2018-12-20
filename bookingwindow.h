#ifndef BOOKINGWINDOW_H
#define BOOKINGWINDOW_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class bookingwindow;
}

class bookingwindow : public QDialog
{
    Q_OBJECT

public:
    explicit bookingwindow(QWidget *parent = nullptr);
    ~bookingwindow();

private:
    Ui::bookingwindow *ui;
    QSqlDatabase database;
    QSqlQueryModel *model;
    QSqlQuery *query;
};

#endif // BOOKINGWINDOW_H
