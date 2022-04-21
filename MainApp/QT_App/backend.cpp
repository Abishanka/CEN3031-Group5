#include "backend.h"
#include "sqlcommand.h"
#include "assingmentlistmodel.h"
#include "filterproxymodel.h"

#include <vector>
#include <QVector>
#include <QNetworkAccessManager>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkReply>
#include <QEventLoop>
#include <QDateTime>
#include <QMap>
#include <QtSql>

using namespace std;
BackEnd::BackEnd()
{

}


sqlcommand BackEnd :: getCourses(QString courseString)
{
    QEventLoop eventLoop;
    BackEnd object;
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

     // make the get request to active courses
    QUrl active_courses(courseString);
    QNetworkRequest request(active_courses);
    QNetworkReply *reply = mgr.get(request);
    eventLoop.exec();

    sqlcommand sql_data;

    QMap<QString,QString> courseData;

    if (reply ->error() == QNetworkReply::NoError)
    {
        QString strReply = reply -> readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
        QJsonArray courses_json_array = jsonResponse.array();
        for(int i=0; i<courses_json_array.size(); i++)
        {
              QJsonObject jsonObj = courses_json_array.at(i).toObject();
              QString courseName = jsonObj.find("name").value().toString();
              int courseID = jsonObj.find("id").value().toInt();

              QString course_id_string = QString :: number(courseID);
              courseData[course_id_string] = courseName;

              QString parameters = "/assignments?per_page=100&access_token="+object.access_token;
              QString courseURL= "https://ufl.instructure.com/api/v1/courses/"+course_id_string+parameters;

              QUrl complete_url(courseURL);
              //qDebug() << complete_url;
              object.request = QNetworkRequest(complete_url);
              object.request_vec.push_back(object.request);
         }
   }
    delete reply;
    sql_data = getAssignmentInfo(object.request_vec,courseData);
    return sql_data;
}

sqlcommand BackEnd :: getAssignmentInfo(QVector<QNetworkRequest> vectorRequest, QMap<QString,QString> course_data)
{
    BackEnd object;
    sqlcommand sqlData;

    QString path = "C:/Users/Thicctoria/Desktop/CEN3031-Group5/MainApp/QT_App/Resources/Database/qt.assignments";
    //QString path = QDir :: current().currentPath()  + "/QT_App/Resources/Database/qt.assignments";
    //qDebug() << path;

    sqlData.createDatabase(path);
    sqlData.createTable();

    for (qsizetype i=0; i < vectorRequest.size();i++)
    {
        QEventLoop eventLoop2;
        QNetworkAccessManager a_mgr;
        QObject::connect(&a_mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop2, SLOT(quit()));
        QNetworkRequest request(vectorRequest[i]);
        QNetworkReply *a_reply = a_mgr.get(request);
        eventLoop2.exec();

        if (a_reply ->error() == QNetworkReply::NoError)
        {
            int ass_course_id;
            QString strReply = a_reply -> readAll();
            QJsonDocument assignment_jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
            QJsonArray assignment_json_array = assignment_jsonResponse.array();

            for(int i=0; i<assignment_json_array.size(); i++)
            {
                QJsonObject jsonObj2 = assignment_json_array.at(i).toObject();
                QString assignmentName = jsonObj2.find("name").value().toString();
                ass_course_id = jsonObj2.find("course_id").value().toInt();
                QString dueDate = jsonObj2.find("due_at").value().toString();

                object.listCourses.push_back(QString :: number(ass_course_id));
                object.course_ID.push_back(QString :: number(ass_course_id));
                object.due_dates.push_back(dueDate);
                object.assignment_names.push_back(assignmentName);

            }
        }
        delete a_reply;
    }
        sqlData.deleteDatabase();
        for(qsizetype i =0; i< object.listCourses.size(); i++)
        {
            //QDateTime dateTime = QDateTime :: fromString(object.due_dates[i],"yyyy-MM-ddTHH:mm:ssZ");
            //object.due_dates[i] = dateTime.toString();
            if(course_data.count(object.listCourses[i]))
            {
                replace(object.listCourses.begin(), object.listCourses.end(), object.listCourses[i],course_data.value(object.listCourses[i]));
            }

            sqlData.addData(object.course_ID[i],object.listCourses[i],object.assignment_names[i],object.due_dates[i]);
            //qDebug() << "CourseID: " << object.course_ID[i] << "CourseName: " << object.listCourses[i] << "Assignment_Name: " << object.assignment_names[i] << "Due Date: " << object.due_dates[i];
       }
    return sqlData;
}
