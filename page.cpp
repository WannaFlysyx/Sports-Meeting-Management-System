#include "page.h"
#include "ui_page.h"

#include <QDebug>
#include <QMainWindow>
#include <QSqlError>
#include<QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSqlRecord>
#include <QTableView>

Page::Page(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Page)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("competition");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("Zaqmlp123456");
    // db.setUserName(username);
    // db.setPassword(password);
    db.open();
    if(!db.isOpen()){
        qDebug()<<"connect success!"<<'\n';
    }
}

Page::~Page()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.close();
    delete ui;
}

int Page::FindCollegeID(){
    QSqlQuery query;
    query.prepare("SELECT ACollegeID FROM Athlete WHERE ASID = :ASID");
    query.bindValue(":ASID", ui->text());
    query.exec();
    int ASID = query.value(0).toInt();
    qDebug() <<"exec next() :"<<ASID;
        // QString row = "CollegeName:  " +CollegeName+"CollegeLeader:  "+CollegeLeader+'\n';
        // ui->textBrowser->setText(row);
    return ASID;
}

void Page::FindAthleteByASID(){
    QSqlQuery query;
    int CollegeID = FindCollegeID();
    query.prepare("SELECT CollegeName,CollegeLeader,Cscore FROM College WHERE CollegeID= :CollegeID");
    query.bindValue(":CollegeID", CollegeID);
    query.exec();
    while (query.next()) {
        QString CollegeName = query.value(0).toString();
        QString CollegeLeader = query.value(1).toString();
        qDebug() <<"exec next() :"<<CollegeName << CollegeLeader;
        QString row = "CollegeName:  " +CollegeName+"CollegeLeader:  "+CollegeLeader+'\n';
        ui->textBrowser->setText(row);
    }

}

void Page::GetData(QString username,QString password){
    this->username = username;
    this->password = password;
}
