#include "test4.h"

#include<QSqlQuery>
#include <QSqlDatabase>
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Test4 w;
    w.show();
    return a.exec();
}
