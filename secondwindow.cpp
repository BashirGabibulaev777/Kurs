#include "ui_secondwindow.h"
#include "mainwindow.h"
#include "secondwindow.h"

secondwindow::secondwindow (QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secondwindow)
{
    ui->setupUi(this);
}

secondwindow::~secondwindow()
{
    delete ui;
}

void secondwindow::on_Add_clicked()
{
    MainWindow connection;
    QString fName, mName, lName, pasport;
    fName = ui->pasteFName->text();
    mName = ui->pasteMName->text();
    lName = ui->pasteLName->text();
    pasport = ui->pastePasport->text();

    if(!connection.connectToSql())
    {
        qDebug() << "Error";
    }

    connection.connectToSql();
    QSqlQuery query;
    query.prepare ("insert into client (fName, mName, lName, pasport) values ('"+fName+"','"+mName+"','"+lName+"','"+pasport+"')");

    if(!query.exec())
    {
        QMessageBox::critical(this, tr("Error"), query.lastError().text());
    }
    else
    {
        QMessageBox::information(this, tr("Save"),tr("Saved"));
    }
}

void secondwindow::on_Delete_clicked()
{
    MainWindow connection;
    QString idC;
    idC = ui->pasteID->text();

    if(!connection.connectToSql())
    {
        qDebug() << "Error";
    }

    connection.connectToSql();
    QSqlQuery query;
    query.prepare ("delete from client where idC = ('"+idC+"')");

    if(!query.exec())
    {
        QMessageBox::critical(this, tr("Error"), query.lastError().text());
    }
    else
    {
        QMessageBox::information(this, tr("Delete"),tr("Deleted"));
    }
}

void secondwindow::on_Book_clicked()
{
    MainWindow connection;
    QString familia, name, otch, startRes, endRes, roomType;
    familia = ui->pasteFName->text();
    name = ui->pasteMName->text();
    otch = ui->pasteLName->text();
    startRes = ui->startResB->text();
    endRes = ui->endResB->text();
    roomType = ui->pasteType->text();

    if(!connection.connectToSql())
    {
        qDebug() << "Error";
    }

    connection.connectToSql();
    QSqlQuery query;
    query.prepare ("insert into reserv (familia, name, otch, startRes, endRes, roomType) values ('"+familia+"','"+name+"','"+otch+"','"+startRes+"','"+endRes+"','"+roomType+"')");

    if(!query.exec())
    {
        QMessageBox::critical(this, tr("Error"), query.lastError().text());
    }
    else
    {
        QMessageBox::information(this, tr("Save"),tr("Saved"));
    }
}



void secondwindow::on_DeleteBook_clicked()
{
    MainWindow connection;
    QString idRes;
    idRes = ui->pasteID->text();

    if(!connection.connectToSql())
    {
        qDebug() << "Error";
    }

    connection.connectToSql();
    QSqlQuery query;
    query.prepare ("delete from reserv where idRes = ('"+idRes+"')");

    if(!query.exec())
    {
        QMessageBox::critical(this, tr("Error"), query.lastError().text());
    }
    else
    {
        QMessageBox::information(this, tr("Delete"),tr("Deleted"));
        //connection.disconnectFromSql();
    }
}
