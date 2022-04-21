#ifndef BACKEND_H
#define BACKEND_H

#include <qqml.h>
#include <QtQml/qqml.h>
#include <sqlcommand.h>
#include "filterproxymodel.h"
#include "assingmentlistmodel.h"

#include <QObject>
#include <QString>
#include <QVector>
#include <QDateTime>
#include <qqml.h>
#include <QAbstractListModel>
#include <QQmlListProperty>
#include <QtQml/qqml.h>
#include <QNetworkRequest>

class BackEnd
{
public:
    QVector<QString> listCourses;
    QVector<QString> assignment_names;
    QVector<QString> due_dates;
    QVector<QString> course_ID;
    sqlcommand getCourses(QString courseString);
    sqlcommand getAssignmentInfo(QVector<QNetworkRequest> requestVector, QMap<QString,QString> course_data);
    QNetworkRequest request;
    QString access_token = "1016~Ac0cFcraqlqoE0u654oBA4mqEOXUMzrqSNABV9tAlCpbnRYG2yBam0DhwUnhYbgH";
    QVector<QNetworkRequest> request_vec;

    BackEnd();
};

#endif // BACKEND_H
