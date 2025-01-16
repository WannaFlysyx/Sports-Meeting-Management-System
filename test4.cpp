#include "ui_test4.h"
#include "test4.h"
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QTableWidget>
#include <QVariant>
#include <QStandardItemModel>
#include <QSqlError>
#include <QStyle>
#include <QMessageBox>

Test4::Test4(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Test4)
{
    ui->setupUi(this);
    ui->label_22->setStyleSheet("color: red;");


    QLinearGradient gradient(ui->pushButton_2->rect().topLeft(), ui->pushButton_2->rect().bottomLeft()); // 从上到下的线性渐变
    gradient.setColorAt(0, Qt::blue);
    gradient.setColorAt(1, Qt::magenta);

    QPalette palette = ui->pushButton_2->palette();
    palette.setBrush(QPalette::Button, QBrush(gradient));
    ui->pushButton_2->setPalette(palette);
    ui->pushButton_2->update();
}

Test4::~Test4()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.close();
    delete ui;
}

void Test4::Button(){
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("competition");
    db.setPort(3306);
    // db.setUserName("root");
    // db.setPassword("Zaqmlp123456");
    db.setUserName(username);
    if(username == "Athlete"){
        ui->lineEdit_4->setStyleSheet("background-color:#49576E;"
                                       "color: white;"
                                       "font-weight: bold;");
        ui->lineEdit_5->setStyleSheet("background-color:#49576E;"
                                      "color: white;"
                                      "font-weight: bold;");
        ui->lineEdit_6->setStyleSheet("background-color:#49576E;"
                                      "color: white;"
                                      "font-weight: bold;");
        ui->lineEdit_8->setStyleSheet("background-color:#49576E;"
                                      "color: white;"
                                      "font-weight: bold;");
        ui->lineEdit_9->setStyleSheet("background-color:#49576E;"
                                      "color: white;"
                                      "font-weight: bold;");
        ui->lineEdit_10->setStyleSheet("background-color:#49576E;"
                                      "color: white;"
                                      "font-weight: bold;");
        ui->lineEdit_11->setStyleSheet("background-color:#49576E;"
                                      "color: white;"
                                      "font-weight: bold;");
        ui->lineEdit_12->setStyleSheet("background-color:#49576E;"
                                      "color: white;"
                                      "font-weight: bold;");
        ui->lineEdit_13->setStyleSheet("background-color:#49576E;"
                                      "color: white;"
                                      "font-weight: bold;");

        ui->label_5->setStyleSheet("color: grey");
        ui->label_6->setStyleSheet("color: grey");
        ui->label_7->setStyleSheet("color: grey");
        ui->label_8->setStyleSheet("color: grey");

        ui->pushButton_6->setStyleSheet("background-color:#49576E;"
                                        "color: grey;"
                                        "border-radius: 6px;"
                                        "font-weight: bold;"
                                        "text-align: center;");
        ui->pushButton_7->setStyleSheet("background-color:#49576E;"
                                        "color: grey;"
                                        "border-radius: 6px;"
                                        "font-weight: bold;"
                                        "text-align: center;");
        ui->pushButton_8->setStyleSheet("background-color:#49576E;"
                                        "color: grey;"
                                        "border-radius: 6px;"
                                        "font-weight: bold;"
                                        "text-align: center;");

        ui->pushButton_4->setStyleSheet("background-color:#49576E;"
                                        "color: grey;"
                                        "border-radius: 6px;"
                                        "font-weight: bold;"
                                        "text-align: center;");
        ui->pushButton_5->setStyleSheet("background-color:#49576E;"
                                        "color: grey;"
                                        "border-radius: 6px;"
                                        "font-weight: bold;"
                                        "text-align: center;");
        ui->pushButton_9->setStyleSheet("background-color:#49576E;"
                                        "color: grey;"
                                        "border-radius: 6px;"
                                        "font-weight: bold;"
                                        "text-align: center;");
        ui->pushButton_10->setStyleSheet("background-color:#49576E;"
                                        "color: grey;"
                                        "border-radius: 6px;"
                                        "font-weight: bold;"
                                        "text-align: center;");
        ui->pushButton_11->setStyleSheet("background-color:#49576E;"
                                        "color: grey;"
                                        "border-radius: 6px;"
                                        "font-weight: bold;"
                                        "text-align: center;");
        ui->pushButton_12->setStyleSheet("background-color:#49576E;"
                                        "color: grey;"
                                        "border-radius: 6px;"
                                        "font-weight: bold;"
                                        "text-align: center;");
        ui->pushButton_13->setStyleSheet("background-color:#49576E;"
                                         "color: grey;"
                                         "border-radius: 6px;"
                                         "font-weight: bold;"
                                         "text-align: center;");

        ui->label_9->setStyleSheet("color: grey");
        ui->label_10->setStyleSheet("color: grey");
        ui->label_11->setStyleSheet("color: grey");

        ui->label_16->setStyleSheet("color: grey");
        ui->label_17->setStyleSheet("color: grey");
        ui->label_18->setStyleSheet("color: grey");
        ui->label_19->setStyleSheet("color: grey");
        ui->label_20->setStyleSheet("color: grey");
        ui->label_21->setStyleSheet("color: grey");

        ui->label_13->setStyleSheet("color: grey");
        ui->label_14->setStyleSheet("color: grey");
        ui->label_15->setStyleSheet("color: grey");
    }
    if(username == "Judge"){
        ui->label_9->setStyleSheet("color: grey");
        ui->label_10->setStyleSheet("color: grey");
        ui->label_11->setStyleSheet("color: grey");

        ui->lineEdit_4->setStyleSheet("background-color:#49576E;"
                                      "color: white;"
                                      "font-weight: bold;");
        ui->lineEdit_5->setStyleSheet("background-color:#49576E;"
                                      "color: white;"
                                      "font-weight: bold;");
        ui->lineEdit_6->setStyleSheet("background-color:#49576E;"
                                      "color: white;"
                                      "font-weight: bold;");
        ui->lineEdit_8->setStyleSheet("background-color:#49576E;"
                                      "color: white;"
                                      "font-weight: bold;");
        ui->lineEdit_9->setStyleSheet("background-color:#49576E;"
                                      "color: white;"
                                      "font-weight: bold;");
        ui->lineEdit_10->setStyleSheet("background-color:#49576E;"
                                       "color: white;"
                                       "font-weight: bold;");
        ui->lineEdit_11->setStyleSheet("background-color:#49576E;"
                                       "color: white;"
                                       "font-weight: bold;");
        ui->lineEdit_12->setStyleSheet("background-color:#49576E;"
                                       "color: white;"
                                       "font-weight: bold;");
        ui->lineEdit_13->setStyleSheet("background-color:#49576E;"
                                       "color: white;"
                                       "font-weight: bold;");

        ui->pushButton_6->setStyleSheet("background-color:#49576E;"
                                        "color: grey;"
                                        "border-radius: 6px;"
                                        "font-weight: bold;"
                                        "text-align: center;");
        ui->pushButton_7->setStyleSheet("background-color:#49576E;"
                                        "color: grey;"
                                        "border-radius: 6px;"
                                        "font-weight: bold;"
                                        "text-align: center;");
        ui->pushButton_8->setStyleSheet("background-color:#49576E;"
                                        "color: grey;"
                                        "border-radius: 6px;"
                                        "font-weight: bold;"
                                        "text-align: center;");
        ui->pushButton_9->setStyleSheet("background-color:#49576E;"
                                        "color: grey;"
                                        "border-radius: 6px;"
                                        "font-weight: bold;"
                                        "text-align: center;");
        ui->pushButton_10->setStyleSheet("background-color:#49576E;"
                                         "color: grey;"
                                         "border-radius: 6px;"
                                         "font-weight: bold;"
                                         "text-align: center;");
        ui->pushButton_11->setStyleSheet("background-color:#49576E;"
                                         "color: grey;"
                                         "border-radius: 6px;"
                                         "font-weight: bold;"
                                         "text-align: center;");
        ui->pushButton_12->setStyleSheet("background-color:#49576E;"
                                         "color: grey;"
                                         "border-radius: 6px;"
                                         "font-weight: bold;"
                                         "text-align: center;");

        ui->label_16->setStyleSheet("color: grey");
        ui->label_17->setStyleSheet("color: grey");
        ui->label_18->setStyleSheet("color: grey");
        ui->label_19->setStyleSheet("color: grey");
        ui->label_20->setStyleSheet("color: grey");
        ui->label_21->setStyleSheet("color: grey");

        ui->label_13->setStyleSheet("color: grey");
        ui->label_14->setStyleSheet("color: grey");
        ui->label_15->setStyleSheet("color: grey");
    }
    db.setPassword(password);
    connection_flag ++;
    if(connection_flag%2==0){
        db.open();
        QSqlQuery query;
        query.exec("SET NAMES utf8mb4 COLLATE utf8mb4_unicode_ci;");
        query.exec("SET character_set_connection=utf8mb4;");
        query.exec("SET character_set_client=utf8mb4;");
        query.exec("SET character_set_results=utf8mb4;");
        if(db.isOpen()){
            qDebug()<<"connect successed!"<<'\n';
            ui->label_22->setStyleSheet("color: green;");
            ui->label_22->setText("已连接");
            ui->pushButton->setText("断开连接");
            ui->lineEdit->setText("");
            ui->lineEdit_2->setText("");
        }
    }
    if(connection_flag%2==1){
        db.close();
        ui->label_22->setStyleSheet("color: white;"
                                    "font-weight: bold;"
                                    "text-align: center;");
        ui->label_22->setText("未连接");
        ui->pushButton->setText("新建连接");

        ui->lineEdit_4->setStyleSheet("background-color:#7E92B5;"
                                      "color: white;"
                                      "font-weight: bold;");
        ui->lineEdit_5->setStyleSheet("background-color:#7E92B5;"
                                      "color: white;"
                                      "font-weight: bold;");
        ui->lineEdit_6->setStyleSheet("background-color:#7E92B5;"
                                      "color: white;"
                                      "font-weight: bold;");
        ui->lineEdit_8->setStyleSheet("background-color:#7E92B5;"
                                      "color: white;"
                                      "font-weight: bold;");
        ui->lineEdit_9->setStyleSheet("background-color:#7E92B5;"
                                      "color: white;"
                                      "font-weight: bold;");
        ui->lineEdit_10->setStyleSheet("background-color:#7E92B5;"
                                       "color: white;"
                                       "font-weight: bold;");
        ui->lineEdit_11->setStyleSheet("background-color:#7E92B5;"
                                       "color: white;"
                                       "font-weight: bold;");
        ui->lineEdit_12->setStyleSheet("background-color:#7E92B5;"
                                       "color: white;"
                                       "font-weight: bold;");
        ui->lineEdit_13->setStyleSheet("background-color:#7E92B5;"
                                       "color: white;"
                                       "font-weight: bold;");

        ui->label_5->setStyleSheet("color: white;"
                                   "font-weight: bold;"
                                   "text-align: center;");
        ui->label_6->setStyleSheet("color: white;"
                                   "font-weight: bold;"
                                   "text-align: center;");
        ui->label_7->setStyleSheet("color: white;"
                                   "font-weight: bold;"
                                   "text-align: center;");
        ui->label_8->setStyleSheet("color: white;"
                                   "font-weight: bold;"
                                   "text-align: center;");

        ui->pushButton_6->setStyleSheet("background-color:#65789B;"
                                        "color: white;"
                                        "border-radius: 6px;"
                                        "font-weight: bold;"
                                        "text-align: center;");
        ui->pushButton_7->setStyleSheet("background-color:#65789B;"
                                        "color: white;"
                                        "border-radius: 6px;"
                                        "font-weight: bold;"
                                        "text-align: center;");
        ui->pushButton_8->setStyleSheet("background-color:#65789B;"
                                        "color: white;"
                                        "border-radius: 6px;"
                                        "font-weight: bold;"
                                        "text-align: center;");

        ui->pushButton_4->setStyleSheet("background-color:#65789B;"
                                        "color: white;"
                                        "border-radius: 6px;"
                                        "font-weight: bold;"
                                        "text-align: center;");
        ui->pushButton_5->setStyleSheet("background-color:#65789B;"
                                        "color: white;"
                                        "border-radius: 6px;"
                                        "font-weight: bold;"
                                        "text-align: center;");
        ui->pushButton_9->setStyleSheet("background-color:#65789B;"
                                        "color: white;"
                                        "border-radius: 6px;"
                                        "font-weight: bold;"
                                        "text-align: center;");
        ui->pushButton_10->setStyleSheet("background-color:#65789B;"
                                         "color: white;"
                                         "border-radius: 6px;"
                                         "font-weight: bold;"
                                         "text-align: center;");
        ui->pushButton_11->setStyleSheet("background-color:#65789B;"
                                         "color: white;"
                                         "border-radius: 6px;"
                                         "font-weight: bold;"
                                         "text-align: center;");
        ui->pushButton_12->setStyleSheet("background-color:#65789B;"
                                         "color: white;"
                                         "border-radius: 6px;"
                                         "font-weight: bold;"
                                         "text-align: center;");

        ui->label_9->setStyleSheet("color: white;"
                                   "font-weight: bold;"
                                   "text-align: center;");
        ui->label_10->setStyleSheet("color: white;"
                                    "font-weight: bold;"
                                    "text-align: center;");
        ui->label_11->setStyleSheet("color: white;"
                                    "font-weight: bold;"
                                    "text-align: center;");

        ui->label_16->setStyleSheet("color: white;"
                                    "font-weight: bold;"
                                    "text-align: center;");
        ui->label_17->setStyleSheet("color: white;"
                                    "font-weight: bold;"
                                    "text-align: center;");
        ui->label_18->setStyleSheet("color: white;"
                                    "font-weight: bold;"
                                    "text-align: center;");
        ui->label_19->setStyleSheet("color: white;"
                                    "font-weight: bold;"
                                    "text-align: center;");
        ui->label_20->setStyleSheet("color: white;"
                                    "font-weight: bold;"
                                    "text-align: center;");
        ui->label_21->setStyleSheet("color: white;"
                                    "font-weight: bold;"
                                    "text-align: center;");

        ui->label_13->setStyleSheet("color: white;"
                                    "font-weight: bold;"
                                    "text-align: center;");
        ui->label_14->setStyleSheet("color: white;"
                                    "font-weight: bold;"
                                    "text-align: center;");
        ui->label_15->setStyleSheet("color: white;"
                                    "font-weight: bold;"
                                    "text-align: center;");

    }
}

void Test4::FindAthleteInfo(){
    QSqlQuery query;
    query.prepare("SELECT AName 运动员姓名,ASex 运动员性别,Ascore 运动员积分,CollegeName 学院名称,CollegeLeader 领队,Cscore 学院总分 FROM College,Athlete WHERE Athlete.ACollegeID = College.CollegeID AND ASID = :ASID");
    query.bindValue(":ASID", ui->lineEdit_3->text());
    ui->lineEdit_3->setText("");
    query.exec();
    ShowInTableView(query);
    if (query.exec())
    {

    }
    else
    {
        qDebug() << query.lastError();
    }
}

void Test4::FindCollegeRank(){
    QSqlQuery query;
    query.prepare("SELECT CollegeName 学院名称,CollegeLeader 领队,Cscore 学院总分,RANK() over(ORDER BY Cscore DESC) 学院排名 FROM College");
    query.exec();
    ShowInTableView(query);
    if (query.exec())
    {

    }
    else
    {
        qDebug() << query.lastError();
    }
}

void Test4::ShowInTableView(QSqlQuery &query){
    int columnCount = query.record().count();
    QStandardItemModel *model = new QStandardItemModel();
    model->setColumnCount(columnCount);
    for (int col = 0; col < columnCount; ++col) {
        model->setHorizontalHeaderItem(col, new QStandardItem(query.record().fieldName(col)));
    }
    while (query.next()) {
        QList<QStandardItem*> rowItems;
        for (int col = 0; col < columnCount; ++col) {
            QString data = query.value(col).toString();
            QStandardItem *item = new QStandardItem(data);
            item->setTextAlignment(Qt::AlignCenter);
            rowItems.append(item);
        }
        model->appendRow(rowItems);
    }

    ui->tableView->setModel(model);
    ui->tableView->setStyleSheet(
        "QTableView {"
        "   background-color: #F0F0F0;"
        // "   alternate-background-color: #E0E0E0;"
        // "   gridline-color: #D0D0D0;"
        "   font-size: 12px;"
        "}"
        "QTableView::item:selected {"
        "   background-color: #ADD8E6;"
        "   color: black;"
        "}"
        );
    ui->tableView->setSelectionMode(QAbstractItemView::ExtendedSelection); //可多选（Ctrl、Shift、 Ctrl+A都可以）
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑
    ui->tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//去掉水平滚动条
    ui->tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);  //去掉垂直滚动条
    ui->tableView->verticalHeader()->setVisible(false);//隐藏侧边表头
    ui->tableView->setAlternatingRowColors(true); //隔行变色
    ui->tableView->setFocusPolicy(Qt::NoFocus); //去除选中虚线框
    ui->tableView->horizontalHeader()->setStyleSheet("QHeaderView::section {"
                                                     "background-color: #4C6080;"
                                                     "color: white;"
                                                     "border-style: none;"
                                                     "padding: 4px;"
                                                     "font-size: 11pt;"
                                                     "text-align: center;"
                                                     "}");
    ui->tableView->verticalHeader()->setStyleSheet("QHeaderView::section {"
                                                   "background-color: #4C6080;"
                                                   "color: white;"
                                                   "border-style: none;"
                                                   "padding: 4px;"
                                                   "font-size: 11pt;"
                                                   "text-align: center;"
                                                   "}");
    QPalette palette;    //调色板
    palette.setColor(QPalette::Base, QColor(255,255,255));   //基底
    palette.setColor(QPalette::AlternateBase, QColor(233,245,252));  //交替基底
    ui->tableView->setPalette(palette);
    ui->tableView->verticalHeader()->setDefaultSectionSize(30); // 设置默认行高
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // 自动拉伸列宽
}

void Test4::AddScore(){
    QSqlQuery query;
    int CompetitionID = ui->spinBox->value();
    int AID = ui->spinBox_2->value();
    int CompetitionRank = ui->spinBox_3->value();
    int CompetitionScore = ui->spinBox_4->value();
    query.prepare("INSERT INTO Score(CompetitionID,AID,CompetitionRank,CompetitionScore) VALUES(:CompetitionID,:AID,:CompetitionRank,:CompetitionScore)");
    query.bindValue(":CompetitionID", CompetitionID);
    query.bindValue(":AID", AID);
    query.bindValue(":CompetitionRank", CompetitionRank);
    query.bindValue(":CompetitionScore", CompetitionScore);
    if (query.exec())
    {
        QMessageBox::information(this, tr("插入成功"), tr("插入成功！"));
    }
    else
    {
        qDebug() << query.lastError();
        QMessageBox::information(this, tr("插入成绩错误"), tr(query.lastError().databaseText().toLocal8Bit()));
    }
}

void Test4::FindAllScore(){
    QSqlQuery query;
    query.prepare("SELECT CompetitionID 比赛ID,AID 运动员ID, CompetitionRank 比赛排名,CompetitionScore 比赛分数 FROM Score");
    query.exec();
    ShowInTableView(query);
}

void Test4::AddCompetition(){
    QSqlQuery query;
    int CompetitionID = ui->spinBox_5->value();
    QString CompetitionSex = ui->lineEdit_4->text();
    ui->lineEdit_4->setText("");
    QString CompetitionName = ui->lineEdit_5->text();
    ui->lineEdit_5->setText("");
    query.prepare("INSERT INTO Competition(CompetitionID,CompetitionSex,CompetitionName) VALUES(:CompetitionID,:CompetitionSex,:CompetitionName)");
    query.bindValue(":CompetitionID", CompetitionID);
    query.bindValue(":CompetitionSex", CompetitionSex);
    query.bindValue(":CompetitionName", CompetitionName);
    if (query.exec())
    {
        QMessageBox::information(this, tr("插入比赛成功"), tr("插入比赛信息成功！"));
    }
    else
    {
        qDebug() << query.lastError();
        QMessageBox::information(this, tr("插入比赛错误"), tr(query.lastError().databaseText().toLocal8Bit()));
    }
}

void Test4::DeleteCompetition(){
    QSqlQuery query;
    QString CompetitionName = ui->lineEdit_5->text();
    ui->lineEdit_5->setText("");
    query.prepare("DELETE FROM Competition WHERE CompetitionName = :CompetitionName");
    query.bindValue(":CompetitionName", CompetitionName);
    if (query.exec())
    {
        QMessageBox::information(this, tr("删除比赛成功"), tr("删除比赛信息成功！"));
    }
    else
    {
        qDebug() << query.lastError();
        QMessageBox::information(this, tr("删除比赛错误"), tr(query.lastError().databaseText().toLocal8Bit()));
    }
}

void Test4::UpdateCompetition(){
    QSqlQuery query;
    QString OldCompetitionName = ui->lineEdit_5->text();
    ui->lineEdit_5->setText("");
    QString CompetitionName = ui->lineEdit_6->text();
    ui->lineEdit_6->setText("");
    query.prepare("UPDATE Competition SET CompetitionName = :CompetitionName WHERE CompetitionName = :OldCompetitionName");
    query.bindValue(":OldCompetitionName", OldCompetitionName);
    query.bindValue(":CompetitionName", CompetitionName);
    if (query.exec())
    {
        QMessageBox::information(this, tr("更新比赛成功"), tr("更新比赛信息成功！"));
    }
    else
    {
        qDebug() << query.lastError();
        QMessageBox::information(this, tr("更新比赛错误"), tr(query.lastError().databaseText().toLocal8Bit()));
    }
}

void Test4::AddCollege(){
    QSqlQuery query;
    int CollegeID = ui->spinBox_6->value();
    QString CollegeName = ui->lineEdit_10->text();
    ui->lineEdit_10->setText("");
    QString CollegeLeader = ui->lineEdit_11->text();
    ui->lineEdit_11->setText("");
    int Cscore = ui->spinBox_7->value();
    query.prepare("INSERT INTO College(CollegeID,CollegeName,CollegeLeader,Cscore) VALUES(:CollegeID,:CollegeName,:CollegeLeader,:Cscore)");
    query.bindValue(":CollegeID", CollegeID);
    query.bindValue(":CollegeName", CollegeName);
    query.bindValue(":CollegeLeader", CollegeLeader);
    query.bindValue(":Cscore", Cscore);
    if (query.exec())
    {
        QMessageBox::information(this, tr("插入学院成功"), tr("插入学院信息成功！"));
    }
    else
    {
        qDebug() << query.lastError();
        QMessageBox::information(this, tr("插入学院错误"), tr(query.lastError().databaseText().toLocal8Bit()));
    }
}

void Test4::UpdateLeader(){
    QSqlQuery query;
    QString OldCollegeLeader = ui->lineEdit_11->text();
    ui->lineEdit_11->setText("");
    QString CollegeLeader = ui->lineEdit_12->text();
    ui->lineEdit_12->setText("");
    query.prepare("UPDATE College SET CollegeLeader = :CollegeLeader WHERE CollegeLeader = :OldCollegeLeader");
    query.bindValue(":CollegeLeader", CollegeLeader);
    query.bindValue(":OldCollegeLeader", OldCollegeLeader);
    if (query.exec())
    {
        QMessageBox::information(this, tr("更新成功"), tr("更新领队信息成功！"));
    }
    else
    {
        qDebug() << query.lastError();
        QMessageBox::information(this, tr("更新领队错误"), tr(query.lastError().databaseText().toLocal8Bit()));
    }
}

void Test4::AddAthlete(){
    QSqlQuery query;
    int AID = ui->spinBox_10->value();
    QString AName = ui->lineEdit_8->text();
    ui->lineEdit_8->setText("");
    QString ASex = ui->lineEdit_9->text();
    ui->lineEdit_9->setText("");
    int ACollegeID = ui->spinBox_8->value();
    int AScore = ui->spinBox_9->value();
    QString ASID = ui->lineEdit_13->text();
    ui->lineEdit_13->setText("");
    query.prepare("INSERT INTO Athlete(AID,AName,ASex,ACollegeID,AScore,ASID) VALUES(:AID,:AName,:ASex,:ACollegeID,:AScore,:ASID)");
    query.bindValue(":AID", AID);
    query.bindValue(":AName", AName);
    query.bindValue(":ASex", ASex);
    query.bindValue(":ACollegeID", ACollegeID);
    query.bindValue(":AScore", AScore);
    query.bindValue(":ASID", ASID);
    if (query.exec())
    {
        QMessageBox::information(this, tr("插入运动员成功"), tr("插入运动员信息成功！"));
    }
    else
    {
        qDebug() << query.lastError();
        QMessageBox::information(this, tr("添加运动员错误"), tr(query.lastError().databaseText().toLocal8Bit()));
    }
}

void Test4::DeleteAthlete(){
    QSqlQuery query;
    QString ASID = ui->lineEdit_13->text();
    ui->lineEdit_13->setText("");
    query.prepare("DELETE FROM Athlete WHERE ASID = :ASID");
    query.bindValue(":ASID", ASID);
    if (query.exec())
    {
        QMessageBox::information(this, tr("删除运动员成功"), tr("删除运动员信息成功！"));
    }
    else
    {
        qDebug() << query.lastError();
        QMessageBox::information(this, tr("删除运动员错误"), tr(query.lastError().databaseText().toLocal8Bit()));
    }
}

void Test4::FindAllAthlete(){
    QSqlQuery query;
    query.prepare("SELECT AID 运动员ID,AName 运动员姓名,ASex 运动员性别,ACollegeID 学院ID,AScore 运动员分数,ASID 运动员学号 FROM Athlete");
    if (query.exec())
    {
        ShowInTableView(query);
    }
    else
    {
        qDebug() <<query.lastError();
    }
}

void Test4::FindAllCompetition(){
    QSqlQuery query;
    query.prepare("SELECT CompetitionID 比赛ID,CompetitionSex 比赛性别,CompetitionName 比赛名称 FROM Competition");
    query.exec();
    if (query.exec())
    {
        ShowInTableView(query);
    }
    else
    {
        qDebug() << query.lastError();
    }
}

void Test4::FindAthleteCompetition(){
    QSqlQuery query;
    query.prepare("SELECT CompetitionName 比赛名称,CompetitionRank 比赛排名,CompetitionScore 比赛分数 FROM Score,Athlete,Competition WHERE Score.AID = Athlete.AID AND Competition.CompetitionID=Score.CompetitionID AND Athlete.ASID =:ASID");
    QString ASID = ui->lineEdit_3->text();
    ui->lineEdit_3->setText("");
    query.bindValue(":ASID",ASID);
    query.exec();
    if (query.exec())
    {
        ShowInTableView(query);
    }
    else
    {
        qDebug() << query.lastError();
    }
}
