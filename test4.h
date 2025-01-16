#ifndef TEST4_H
#define TEST4_H
#pragma set_character_
#include <QSqlDatabase>
#include <QWidget>
#include<QSqlQuery>

QT_BEGIN_NAMESPACE
namespace Ui {
class Test4;
}
QT_END_NAMESPACE

class Test4 : public QWidget
{
    Q_OBJECT

public:
    Test4(QWidget *parent = nullptr);
    ~Test4();

private:
    Ui::Test4 *ui;
    qint8 connection_flag=1;

private slots:
    void FindAthleteInfo();
    void FindCollegeRank();
    void ShowInTableView(QSqlQuery & query);
    void Button();
    void AddScore();
    void FindAllScore();
    void AddCompetition();
    void DeleteCompetition();
    void UpdateCompetition();
    void AddCollege();
    void UpdateLeader();
    void AddAthlete();
    void DeleteAthlete();
    void FindAllAthlete();
    void FindAllCompetition();
    void FindAthleteCompetition();
};
#endif // TEST4_H
