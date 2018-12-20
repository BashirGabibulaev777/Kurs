#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class clientwindow;
}

class clientwindow : public QDialog
{
    Q_OBJECT

public:
    explicit clientwindow(QWidget *parent = nullptr);
    ~clientwindow();

private:
    Ui::clientwindow *ui;
    QSqlDatabase database;
    QSqlQueryModel *model;
    QSqlQuery *query;
};

#endif // CLIENTWINDOW_H
