#include "bookingwindow.h"
#include "ui_bookingwindow.h"
#include "mainwindow.h"

bookingwindow::bookingwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bookingwindow)
{
    ui->setupUi(this);

    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setDatabaseName("hotel");
    database.setHostName("localhost");
    database.setUserName("root");
    database.setPassword("toor");
    database.setPort(3306);
    model = new QSqlTableModel(this, database);
    if(database.open())
    {
        qDebug() << "Success";
        query = new QSqlQuery(database);
        query->prepare("select * from reserv");
        query->exec();

        model->setQuery(*query);
        ui->tableView->setModel(model);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        model->setHeaderData(0, Qt::Horizontal, tr("ID order"));
        model->setHeaderData(1, Qt::Horizontal, tr("Surname"));
        model->setHeaderData(2, Qt::Horizontal, tr("Name"));
        model->setHeaderData(3, Qt::Horizontal, tr("Patronymic"));
        model->setHeaderData(4, Qt::Horizontal, tr("Start order"));
        model->setHeaderData(5, Qt::Horizontal, tr("End order"));
        model->setHeaderData(6, Qt::Horizontal, tr("Room type"));
    }
    else
    {
        QMessageBox::critical(this, "Error", model->lastError().text());
    }
}

bookingwindow::~bookingwindow()
{
    delete ui;
}
