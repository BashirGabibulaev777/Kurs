#include "roomtype.h"
#include "ui_roomtype.h"
#include "mainwindow.h"

roomType::roomType(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::roomType)
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
        query->prepare("select * from type");
        query->exec();

        model->setQuery(*query);
        ui->tableView->setModel(model);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        model->setHeaderData(0, Qt::Horizontal, tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, tr("Tupe"));
    }
    else
    {
        QMessageBox::critical(this, "Error", model->lastError().text());
    }
}

roomType::~roomType()
{
    delete ui;
}
