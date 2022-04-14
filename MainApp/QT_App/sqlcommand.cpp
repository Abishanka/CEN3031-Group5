#include "sqlcommand.h"
#include <QCoreApplication>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QGuiApplication>
#include <vector>
#include <QQmlApplicationEngine>
using namespace std;
sqlcommand::sqlcommand()
{


}
void sqlcommand::createDatabase(QString path){

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName(path);

    if(!db.open())
    {
        qDebug() << "Can't Connect to DB !";
    }


}
void sqlcommand::createTable(){
    QSqlQuery qry;
    qry.prepare("create table IF NOT EXISTS database ("
              "ID varchar(20),"
              "className varchar(50),"
               "assignment varchar(50),"
                "duedate DATETIME);");
    if(!qry.exec()){
        qDebug()<<"error adding table";
    }
}
void sqlcommand::addData(QString courseID, QString courseName, QString assignmentName, QString date){
    QSqlQuery qry;
    qry.prepare("INSERT INTO database  ("
                "ID,"
                "className,"
                "assignment,"
                 "duedate)"
           "VALUES (?,?,?,?);");

    qry.addBindValue(courseID);
    qry.addBindValue(courseName);
    qry.addBindValue(assignmentName);
    qDebug() <<date;
    qry.addBindValue(QDateTime::fromString(date, "yyyy-MM-ddTHH:mm:ss.zzz"));
//yyyy-MM-dd hh:mm:ss
    if(!qry.exec()){
        qDebug()<<"error adding values to db";
    }
}

 //not done yet
 vector<vector<QString>> sqlcommand::getData(QString dueTime){
    vector<vector<QString>> assignmentVector;
     QSqlQuery qry;
     qry.prepare("SELECT * FROM database where duedate < ? ");
    // qry.prepare("SELECT * FROM database");
     qry.addBindValue(dueTime);
     if(!qry.exec()){
         qDebug()<<"error selecting values from db with Time";
     }


     int id = qry.record().indexOf("ID");
     int classname = qry.record().indexOf("className");
     int assignmentName = qry.record().indexOf("assignment");
     int date = qry.record().indexOf("duedate");

   //  QString test= qry.value(date).toString();
  //   qDebug() << test;
    int x = 0;

     while(qry.next()){
        vector<QString> tempVector;
        QString courseID = qry.value(id).toString();
        QString className = qry.value(classname).toString();
        QString assignment = qry.value(assignmentName).toString();
        QString duedate = qry.value(date).toString();

         qDebug() << courseID << " " << className << " " << assignment << " " << duedate;
        qDebug()<< "values";
       tempVector.push_back(courseID);
       tempVector.push_back(className);
       tempVector.push_back(assignment);
       tempVector.push_back(duedate);



         assignmentVector.push_back(tempVector);
         x++;
  }

    return assignmentVector;

}

void sqlcommand::deleteDatabase(){
   QSqlQuery qry;
    qry.prepare("DELETE FROM database");
   if(!qry.exec()){

     qDebug()<<"error removing db";
   }



}
