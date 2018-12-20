#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtDebug>
#include <QTableView>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlTableModel>
#include <QString>

namespace Ui {
class MainWindow;
bool connectToSql();
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    bool connectToSql();

    void disconnectFromSql();

    ~MainWindow();

private slots:

    void on_AddClient_clicked();

    void on_ShowClient_clicked();

    void on_ShowBooking_clicked();

    void on_roomType_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase database;
    QSqlQueryModel *model;
    QSqlQuery *query;
};

#endif // MAINWINDOW_H
