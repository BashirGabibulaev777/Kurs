#include "clientwindow.h"
#include "ui_clientwindow.h"
#include "mainwindow.h"

clientwindow::clientwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::clientwindow)
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
        query->prepare("select * from client");
        query->exec();

        model->setQuery(*query);
        ui->tableView->setModel(model);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        model->setHeaderData(0, Qt::Horizontal, tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, tr("Surname"));
        model->setHeaderData(2, Qt::Horizontal, tr("Name"));
        model->setHeaderData(3, Qt::Horizontal, tr("Patronymic"));
        model->setHeaderData(4, Qt::Horizontal, tr("Passport"));
    }
    else
    {
        QMessageBox::critical(this, "Error", model->lastError().text());
    }
}

clientwindow::~clientwindow()
{
    delete ui;
}
