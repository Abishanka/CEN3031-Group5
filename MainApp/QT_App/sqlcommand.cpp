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
void createDatabase(QString path){

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName(path);

    if(!db.open())
    {
        qDebug() << "Can't Connect to DB !";
    }


}
void createTable(){
    QSqlQuery qry;
    qry.prepare("create table IF NOT EXISTS database ("
              "ID varchar(20),"
              "className varchar(20),"
               "assignment varchar(20),"
                "duedate DATETIME);");
    if(!qry.exec()){
        qDebug()<<"error adding table";
    }


}
void addData(QString courseID, QString courseName, QString assignmentName, QString date){
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


     qry.addBindValue(QDateTime::fromString(date, "mm-dd-yyyy"));
    if(!qry.exec()){
        qDebug()<<"error adding values to db";
    }



}
 vector<QString> getData(){
    vector<QString> assignmentVector;
     QSqlQuery query("SELECT * FROM person");



     int id = query.record().indexOf("ID");
     int classname = query.record().indexOf("className");
     int assignmentName = query.record().indexOf("assignment");
     int date = query.record().indexOf("duedate");


     while (query.next())
     {
        QString courseID = query.value(id).toString();
        QString className = query.value(classname).toString();
        QString assignment = query.value(assignmentName).toString();
        QString duedate = query.value(date).toString();

       assignmentVector.push_back(courseID);
       assignmentVector.push_back(className);
       assignmentVector.push_back(assignment);
       assignmentVector.push_back(duedate);

     }

    return assignmentVector;

}
void deleteDatabase(){
   QSqlQuery qry;
    qry.prepare("DELETE FROM person");
   if(!qry.exec()){

     qDebug()<<"error removing db";
   }



}
