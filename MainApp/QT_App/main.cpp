#include "sqlcommand.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QCoreApplication>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QtQuick/QQuickWindow>
#include <QtQml>
#include "windows.h"


int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);
    sqlcommand sql;




    //QCoreApplication a(argc, argv);
    const QString DRIVER("QSQLITE");
    QString path = QDir::current().currentPath() + "/Resources/Database/qt.assignments";

             sql.createDatabase(path);
             sql.createTable();
    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/QT_App/main.qml"_qs);

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
