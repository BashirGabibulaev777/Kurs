#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class secondwindow;
}

class secondwindow : public QDialog
{
    Q_OBJECT

public:
    explicit secondwindow(QWidget *parent = nullptr);
    ~secondwindow();

private slots:
    void on_Add_clicked();

    void on_Delete_clicked();

    void on_Book_clicked();

    void on_DeleteBook_clicked();


private:
    Ui::secondwindow *ui;
};

#endif // SECONDWINDOW_H
