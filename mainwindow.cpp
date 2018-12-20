#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secondwindow.h"
#include "clientwindow.h"
#include "bookingwindow.h"
#include "roomtype.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new QSqlTableModel(this, database);
    if(!connectToSql())
        {
            qDebug() << database.lastError().text();
        }
        else
        {
            qDebug() << "Right";
        }
}

bool MainWindow::connectToSql()
{
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setDatabaseName("hotel");
    database.setHostName("localhost");
    database.setUserName("root");
    database.setPassword("toor");
    database.setPort(3306);

    if(database.open())
    {
        qDebug() << "Right!";
        return true;
    }
    else
    {
        QMessageBox::critical(this, "Error", model->lastError().text());
        return false;
    }
}

void MainWindow::disconnectFromSql()
{
    database.close();
    database.removeDatabase(QSqlDatabase::defaultConnection);
}

MainWindow::~MainWindow()
{
    delete model;
    delete query;
    delete ui;
}

void MainWindow::on_AddClient_clicked()
{
    secondwindow windowSec;
    windowSec.setModal(true);
    windowSec.exec();
}

void MainWindow::on_ShowClient_clicked()
{
    clientwindow windowC;
    windowC.setModal(true);
    windowC.exec();
}

void MainWindow::on_ShowBooking_clicked()
{
    bookingwindow windowB;
    windowB.setModal(true);
    windowB.exec();
}

void MainWindow::on_roomType_clicked()
{
    roomType windowT;
    windowT.setModal(true);
    windowT.exec();
}
