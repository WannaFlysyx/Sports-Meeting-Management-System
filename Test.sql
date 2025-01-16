CREATE DATABASE competition
USE competition
CREATE TABLE Athlete(AID INT PRIMARY KEY,
										 AName VARCHAR(40),
										 ASex VARCHAR(255),
										 ACollegeID INT,
										 AScore INT,
										 ASID VARCHAR(255),
										 FOREIGN KEY (ACollegeID) REFERENCES College(CollegeID))
CREATE TABLE Score(CompetitionID INT,
									 AID INT,
									 CompetitionRank INT,
									 CompetitionScore INT CONSTRAINT C1 CHECK(CompetitionScore >=3 AND CompetitionScore <=10),
									 PRIMARY KEY(CompetitionID,AID),
									 FOREIGN KEY (CompetitionID) REFERENCES Competition(CompetitionID),
									 FOREIGN KEY (AID) REFERENCES Athlete(AID)                             )
CREATE TABLE Competition(CompetitionID INT PRIMARY KEY,
												 CompetitionSex VARCHAR(2),
												 CompetitionName VARCHAR(255))
CREATE TABLE College(CollegeID INT PRIMARY KEY,
										 CollegeName VARCHAR(255),
										 CollegeLeader VARCHAR(40),
										 Cscore INT)
										 
--创建Athlete的角色，每创建一个用户将权限复制给用户，角色不变用户变更
CREATE ROLE 'Athlete'
GRANT SELECT ON TABLE College TO 'Athlete'
GRANT SELECT ON TABLE Competition TO 'Athlete'
GRANT SELECT ON TABLE Athlete TO 'Athlete'
SHOW GRANTS FOR 'Athlete'
CREATE USER 'Athlete'@'localhost' IDENTIFIED BY 'Athlete123456'
GRANT 'Athlete' TO 'Athlete'@'localhost'
DROP USER 'Athlete'@'localhost'

CREATE ROLE 'Judge'
GRANT SELECT ON TABLE College TO 'Judge'
GRANT SELECT ON TABLE Competition TO 'Judge'
GRANT SELECT ON TABLE Athlete TO 'Judge'
GRANT INSERT ON TABLE Score TO 'Judge'
SHOW GRANTS FOR 'Judge'
CREATE USER 'Judge'@'localhost' IDENTIFIED BY 'Judge123456'
GRANT 'Judge' TO 'Judge'@'localhost'
DROP USER 'Judge'@'localhost'

CREATE ROLE 'Manage'
GRANT ALL PRIVILEGES ON TABLE College TO 'Manage'
GRANT ALL PRIVILEGES ON TABLE Score TO 'Manage'
GRANT ALL PRIVILEGES ON TABLE Competition TO 'Manage'
GRANT ALL PRIVILEGES ON TABLE Athlete TO 'Manage'
SHOW GRANTS FOR 'Manage'
CREATE USER 'Manage'@'localhost' IDENTIFIED BY 'Manage123456'
GRANT 'Manage' TO 'Manage'@'localhost'
DROP USER 'Manage'@'localhost'


--在运动员获得积分之后将积分写入个人的记录
CREATE TRIGGER Athlete_trigger AFTER INSERT ON Score FOR EACH ROW BEGIN UPDATE Athlete set Athlete.AScore = NEW.CompetitionScore + Athlete.AScore where NEW.AID = Athlete.AID; END
--测试
INSERT INTO Score(CompetitionID,AID,CompetitionRank,CompetitionScore) VALUES(4,10,2,8)

--在运动员积分写入之后写入学院总积分
CREATE TRIGGER College_trigger AFTER UPDATE ON Score FOR EACH ROW BEGIN UPDATE College SET College.Cscore=College.Cscore + (NEW.AScore-OLD.AScore) WHERE NEW.ACollegeID = College.CollegeID; END

--查看运动员所在学院的名称、领队、本学院的总积分(ASID为需要传来的数据)
SELECT AName,ASex,Ascore,CollegeName 学院名称,CollegeLeader 领队,Cscore 学院总分 FROM College,Athlete WHERE Athlete.ACollegeID = College.CollegeID AND ASID = '111111111'
--查看运动员所在学院的总名次
SELECT CollegeName 学院名称,CollegeLeader 领队,Cscore 学院总分,RANK() over(ORDER BY Cscore DESC) 学院排名 FROM College
--查看运动员参加比赛的项目、每个项目的成绩、积分
SELECT DISTINCT CompetitionName 项目名称,CompetitionRank 比赛排名,CompetitionScore 比赛分数 FROM Score,Competition,Athlete WHERE Score.CompetitionID=Competition.CompetitionID AND Athlete.AID = Score.AID AND ASID = '111111111'
--记录运动员参加比赛项目的成绩
INSERT INTO Score(CompetitionID,AID,CompetitionRank,CompetitionScore)  VALUES(1,1,5,3)
--查看运动员参加比赛项目的成绩、积分、名次
SELECT DISTINCT CompetitionName 项目名称,AName 运动员名称,CompetitionRank 比赛排名,CompetitionScore 比赛分数 FROM Score,Competition,Athlete WHERE Score.CompetitionID=Competition.CompetitionID AND Athlete.AID = Score.AID AND ASID = '111111111'
--查看各学院的总积分、总名次等
SELECT CollegeName 学院名称,CollegeLeader 领队,Cscore 学院总分,RANK() over(ORDER BY Cscore DESC) 学院排名 FROM College
--可以管理（增加、删除、修改）比赛项目
INSERT INTO Competition(CompetitionID,CompetitionSex,CompetitionName) VALUES(5,'男','AMC')
DELETE FROM Competition WHERE CompetitionName = 'ACM'
UPDATE Competition SET CompetitionName = 'ACM' WHERE CompetitionName = 'AMC'
--可以管理学院信息
INSERT INTO College(CollegeID,CollegeName,CollegeLeader,Cscore) VALUES(3,'体育馆','WannaFly',100)
DELETE FROM College WHERE CollegeName = '体育馆'
UPDATE College SET CollegeName = '新体育馆' WHERE CollegeName = '体育馆'
--可以管理每个学院的参赛运动员信息
INSERT INTO Athlete(AID,AName,ASex,ACollegeID,AScore,ASID) VALUES(11,'WannaFly','男',1,120,1111111111)
DELETE FROM Athlete WHERE AName = 'WannaFly'
UPDATE Athlete SET AName = '新WannaFly' WHERE AName = 'WannaFly'