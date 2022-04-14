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
#include "windows.h"
#include "backend.h"

using namespace std;


int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);


    qmlRegisterType<BackEnd>("com.backend.assingment", 1, 0, "BackEnd");

    sqlcommand sqlData;

       //    QString path = QDir::current().currentPath() + "/Resources/Database/qt.assignments";
   QString path = "C:/Users/andre/OneDrive/Documents/CEN3031-Group5/MainApp/QT_App/Resources/Database/qt.assignments";
   QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

              sqlData.createDatabase(path);
             sqlData.createTable();
             sqlData.addData("Cen 3101", "Intro to Software Engineering", "Spring Review", "2021-01-30T00:12:00.000");
             vector<vector<QString>>  v1 = sqlData.getData("2021-02-20T00:00:00.000");
//             sqlData.deleteDatabase();


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
