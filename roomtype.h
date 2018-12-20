#ifndef ROOMTYPE_H
#define ROOMTYPE_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class roomType;
}

class roomType : public QDialog
{
    Q_OBJECT

public:
    explicit roomType(QWidget *parent = nullptr);
    ~roomType();

private:
    Ui::roomType *ui;
    QSqlDatabase database;
    QSqlQueryModel *model;
    QSqlQuery *query;
};

#endif // ROOMTYPE_H
