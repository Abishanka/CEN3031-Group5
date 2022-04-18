#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QString>
#include <QVector>
#include <QDateTime>
#include <qqml.h>
#include <QAbstractListModel>
#include <QQmlListProperty>
#include <QtQml/qqml.h>
#include <QNetworkRequest>

class BackEnd : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT
    Q_DISABLE_COPY(BackEnd)

    Q_PROPERTY(int count READ count NOTIFY countChanged)
    Q_PROPERTY(QQmlListProperty<QObject> content READ content)
    Q_CLASSINFO("DefaultProperty", "content")

private:
    class assignmentsInfo {
    public:
        QString cName;  //course name
        QString aName;  //assignment name
        QDateTime dDate;    //due date
    };

public:
    QVector<QString> listCourses;
    QVector<QString> assignment_names;
    QVector<QString> due_dates;
    QVector<QString> course_ID;
    QNetworkRequest request;
    QString access_token = "1016~4dnAMKpSxP9OzNoxtJOYw8DAgXz4KSLlshQLRMU2sMQvBMO3wrZZlw4ia2bIJCbt"; // add token
    QVector<QNetworkRequest> request_vec;

    explicit BackEnd(QObject *parent = nullptr);
    //static void registerTypes(const char *uri);
    QQmlListProperty<QObject> content();


    int count() const;
    QVector<assignmentsInfo> assignments;


    int rowCount(const QModelIndex &p) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;


private:
    int m_count;
    QList<QObject*> m_data;


signals:

    void countChanged(int count);

public slots:
    Q_INVOKABLE void append(QObject* o);
    Q_INVOKABLE void insert(QObject* o, int i);
    Q_INVOKABLE QObject* get(int i);

    static void backEndAppend(QQmlListProperty<QObject> *list, QObject *e);
    static long long int backEndCount(QQmlListProperty<QObject> *list);
    static QObject* backEndAt(QQmlListProperty<QObject> *list, long long int i);
    static void backEndClear(QQmlListProperty<QObject> *list);

};

#endif // BACKEND_H
