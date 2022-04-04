#include "sqlcommand.h"
#include <QCoreApplication>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
sqlcommand::sqlcommand()
{


}
void createDatabase(QString path){

    qDebug()<<"start";

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
                "duedate DATETIME,"
                "displayed bool);");
    if(!qry.exec()){
        qDebug()<<"error adding table";
    }


}
void addData(QString courseID, QString courseName, QString assignmentName, QString date, bool displayed){
    QSqlQuery qry;
    qry.prepare("INSERT INTO database  ("
                "ID,"
                "className,"
                "assignment,"
                 "duedate,"
                "displayed)"
           "VALUES (?,?,?,?,?);");


    qry.addBindValue(courseID);
    qry.addBindValue(courseName);
    qry.addBindValue(assignmentName);


     qry.addBindValue(QDateTime::fromString(date, "mm-dd-yyyy"));
     qry.addBindValue(displayed);
    if(!qry.exec()){
        qDebug()<<"error adding values to db";
    }



}
 void removeData(){



}
void deleteDatabase(){
   QSqlQuery qry;
    qry.prepare("DELETE FROM person");
   if(!qry.exec()){

     qDebug()<<"error removing db";
   }



}
