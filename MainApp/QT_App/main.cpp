#include "sqlcommand.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QCoreApplication>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QtQuick/QQuickWindow>
#include <QtQml>
#include <QDateTime>
#include <qqml.h>
#include <QQuickView>
#include <QAbstractListModel>
#include <QQmlListProperty>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QCoreApplication>
#include <QNetworkReply>
#include <QVector>
#include <QMap>

#include "windows.h"
#include "backend.h"

using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc,argv);

       QEventLoop eventLoop;

       BackEnd object;
       QNetworkAccessManager mgr;
       QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
       QString course_url = "https://ufl.instructure.com/api/v1/courses?enrollment_state=active&access_token=";
       course_url.append(object.access_token);

       // make the get request to active courses
       QUrl active_courses(course_url);
       QNetworkRequest request(active_courses);
       QNetworkReply *reply = mgr.get(request);
       eventLoop.exec();

       QJsonDocument jsonResponse;
       QJsonObject jsonObj;
       QString courseName;
       QString assignmentName;
       QString dueDate;
       int courseID;

       QMap<QString,QString> courseData;
       QMap<QString,QString>::ConstIterator iter;

       if (reply ->error() == QNetworkReply::NoError) {
        QString strReply = reply -> readAll();
        jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
        QJsonArray courses_json_array = jsonResponse.array();
        for(int i=0; i<courses_json_array.size(); i++)
        {
            QJsonObject jsonObj = courses_json_array.at(i).toObject();
            courseName = jsonObj.find("name").value().toString();
            courseID = jsonObj.find("id").value().toInt();

            QString course_id_string = QString :: number(courseID);
            courseData[course_id_string] = courseName;

            QString courseURL= "https://ufl.instructure.com/api/v1/courses/";
            courseURL.append(course_id_string);
            QString parameters = ("/assignments?per_page=100&access_token=");
            parameters.append(object.access_token);
            courseURL.append(parameters);

            QUrl complete_url(courseURL);
            object.request = QNetworkRequest(complete_url);
            object.request_vec.push_back(object.request);
       }

            for (size_t i=0; i < object.request_vec.size();i++)
            {
                QEventLoop eventLoop2;
                QNetworkAccessManager a_mgr;
                QObject::connect(&a_mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop2, SLOT(quit()));
                QNetworkRequest request(object.request_vec[i]);
                QNetworkReply *a_reply = a_mgr.get(request);
                eventLoop2.exec();
                QJsonDocument jsonResponse2;

                if (a_reply ->error() == QNetworkReply::NoError)
                {
                    int ass_course_id;
                    QString strReply = a_reply -> readAll();
                    jsonResponse2 = QJsonDocument::fromJson(strReply.toUtf8());
                    QJsonArray assign_json_array = jsonResponse2.array();

                   for(int i=0; i<assign_json_array.size(); i++)
                   {
                       QJsonObject jsonObj2 = assign_json_array.at(i).toObject();
                       assignmentName = jsonObj2.find("name").value().toString();
                       ass_course_id = jsonObj2.find("course_id").value().toInt();
                       dueDate = jsonObj2.find("due_at").value().toString();
                       object.listCourses.push_back(QString :: number(ass_course_id));
                       object.course_ID.push_back(QString :: number(ass_course_id));
                       object.due_dates.push_back(dueDate);
                       object.assignment_names.push_back(assignmentName);
                    }
                }
                delete a_reply;
           }
        delete reply;
       }



    QGuiApplication app(argc, argv);


    qmlRegisterType<BackEnd>("com.backend.assingment", 1, 0, "BackEnd");



       //    QString path = QDir::current().currentPath() + "/Resources/Database/qt.assignments";
    sqlcommand sqlData;

   QString path = "C:/Users/Andre/OneDrive/Documents/CEN3031-Group5/MainApp/QT_App/Resources/Database/qt.assignments";
   QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

   sqlData.createDatabase(path);
   sqlData.createTable();
   for(qsizetype i =0; i< object.listCourses.size(); i++)
   {
      if(courseData.count(object.listCourses[i]))
      {
       replace(object.listCourses.begin(), object.listCourses.end(), object.listCourses[i],courseData.value(object.listCourses[i]));
      }

      sqlData.addData(object.course_ID[i],object.listCourses[i],object.assignment_names[i],object.due_dates[i]);
      qDebug() << "CourseID: " << object.course_ID[i] << "CourseName: " << object.listCourses[i] << "Assignment_Name: " << object.assignment_names[i] << "Due Date: " << object.due_dates[i];
   }



    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/main.qml"_qs);

//    QQmlComponent component(engine, QUrl::fromLocalFile("main.qml"));
//    QObject *mainQML = component.create();

//    QObject *tool = mainQML->findChild<QObject*>("tool");
//    if (tool)
//        QQmlProperty(tool, size);
//        //tool->setProperty(setIconSize(QSize(100, 100)));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
