#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QCoreApplication>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QtQuick/QQuickWindow>
#include <QtQml>
#include "windows.h"
#include "backend.h"


int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);
    qmlRegisterType<BackEnd>("com.backend.assingment", 1, 0, "BackEnd");


    //TODO QCoreApplication line below is causing crashes

    //QCoreApplication a(argc, argv);
    //const QString DRIVER("QSQLITE");
    //QString path = QDir::current().currentPath() + "/Resources/Database/qt.assignments";

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
