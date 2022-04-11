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

class BackEnd : public QAbstractListModel
{
    Q_OBJECT
<<<<<<< HEAD
=======
  // Q_PROPERTY(type name READ name WRITE setName NOTIFY nameChanged)
>>>>>>> 24aef10b67ede9216e9718c03907a5a8b78cba95
    QML_ELEMENT
    Q_DISABLE_COPY(BackEnd)

<<<<<<< HEAD
    Q_PROPERTY(int count READ count NOTIFY countChanged)
    Q_PROPERTY(QQmlListProperty<QObject> content READ content)
    Q_CLASSINFO("DefaultProperty", "content")
=======
private:
    class assignmentsInfo {
    public:
        QString cName;  //course name
        QString aName;  //assignment name
        QDateTime dDate;    //due date
    };
>>>>>>> 24aef10b67ede9216e9718c03907a5a8b78cba95

public:

    explicit BackEnd(QObject *parent = nullptr);
    //static void registerTypes(const char *uri);
    QQmlListProperty<QObject> content();

<<<<<<< HEAD
    int count() const;
=======
    QVector<assignmentsInfo> assignments;
>>>>>>> 24aef10b67ede9216e9718c03907a5a8b78cba95

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
