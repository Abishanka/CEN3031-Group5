#include "sqlcommand.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QCoreApplication>
#include <QtSql>
#include <QQmlContext>
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
#include "assingmentlistmodel.h"
#include "filterproxymodel.h"

using namespace std;


int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);

    AssingmentListModel listModel;

    QString n = "Abishanka Saha";
    QString c = "Exploring Fine Ass Since";
    QDateTime d = QDateTime::currentDateTime();

    listModel.addData(n, c, d);
    n = "Bruh";
    c = "STOP BEING MAD PLS";

    listModel.addData(n, c, d);

    n = "Rutvi Shukla"
           ;
    c = "Introduction to Having a Fine Ass";

    listModel.addData(n,c,d);

    FilterProxyModel filterModel;
    filterModel.setSourceModel(&listModel);
    filterModel.setFilterRole(assingmentNameRole);
    filterModel.setSortRole(assingmentNameRole);

    qmlRegisterType<BackEnd>("com.backend.assingment", 1, 0, "BackEnd");

//    sqlcommand sqlData;

//    //    QString path = QDir::current().currentPath() + "/Resources/Database/qt.assignments";
//    //test
//    QString path = "C:/Users/andre/OneDrive/Documents/CEN3031-Group5/MainApp/QT_App/Resources/Database/qt.assignments";
//    //  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//        //EXAMPLE CODE TO DRAW FROM/COMMENT IF NECESSARY
//             sqlData.createDatabase(path);
//             sqlData.createTable();
//             //test
//             sqlData.addData("Cen 3101", "Intro to Software Engineering", "Spring Review", "2021-01-30T00:12:00.000");
//             vector<QString> v1 = sqlData.getData();
//             for(unsigned int x = 0; x < v1.size(); x++){
//             qDebug() << v1.at(x);
//               }
//             sqlData.deleteDatabase();


    QQmlApplicationEngine engine;

    QQmlContext* context = engine.rootContext();
    context->setContextProperty("filterModel", &filterModel);


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
