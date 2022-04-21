#include "sqlcommand.h"
#include "windows.h"
#include "backend.h"
#include "assingmentlistmodel.h"
#include "filterproxymodel.h"
#include <qqml.h>
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
#include <QQuickView>
#include <QAbstractListModel>
#include <QQmlListProperty>
#include <QDateTime>

using namespace std;


int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);
    AssingmentListModel listModel;
    BackEnd object;
    sqlcommand sql_data;
    sql_data = object.getCourses("https://ufl.instructure.com/api/v1/courses?enrollment_state=active&access_token="+object.access_token);

    QDateTime today = QDateTime::currentDateTime();
    QDateTime yesterday = today.addDays(-1);
    QString yesterday_str = yesterday.toString("yyyy-MM-dd:HH:mm:ss");
    QDateTime tomorrow = today.addDays(+1);
    QString tomorrow_str = tomorrow.toString("yyyy-MM-dd:HH:mm:ss");

    vector<vector<QString>> data = sql_data.getData(yesterday_str,tomorrow_str);

    for (qsizetype i = 0; i < data.size(); i++) {
        qDebug() << data[i][3];
        QDateTime dateTime = QDateTime :: fromString(data[i][3],"yyyy-MM-ddTHH:mm:ss.zzz");
        listModel.addData(data[i][1],data[i][2],dateTime);
        QString date_time = dateTime.toString();
        qDebug() << date_time;
       }
    //qDebug() << "SIZE OF VECTOR " << data.size();
    //qDebug() << "Yesterday: " << yesterday_str << "Tomorrow: " << tomorrow_str;
    //qDebug() << dateTime;


    FilterProxyModel filterModel;
    filterModel.setSourceModel(&listModel);
    filterModel.setFilterRole(assingmentNameRole);
    filterModel.setSortRole(assingmentNameRole);



    QQmlApplicationEngine engine;

    QQmlContext* context = engine.rootContext();
    context->setContextProperty("filterModel", &filterModel);


    const QUrl url(u"qrc:/main.qml"_qs);

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
