#ifndef PAGE_H
#define PAGE_H

#include <QMainWindow>
#include <QSqlError>
#include<QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include "test4.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Page;
}
QT_END_NAMESPACE

class Page : public QMainWindow
{
    Q_OBJECT

public:
    Page(QWidget *parent = nullptr);
    ~Page();

private:
    Ui::Page *ui;
    QString username;
    QString password;

private slots:
    int FindCollegeID();
    void FindAthleteByASID();
    void GetData(QString username,QString password);
};

#endif // PAGE_H
