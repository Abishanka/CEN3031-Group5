#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QString>
#include <QDateTime>
#include <qqml.h>

class BackEnd : public QObject
{
    Q_OBJECT
    Q_PROPERTY(type name READ name WRITE setName NOTIFY nameChanged)
    QML_ELEMENT

private:
    class assingmentInfo {
    public:
        QString cName;  //course name
        QString aName;  //assignment name
        QDateTime dDate;    //due date
    };

public:
    explicit BackEnd(QObject *parent = nullptr);

    QVector<assingmentInfo> assingments;

    QString c_Name();
    void set_c_Name(QString c_Name);

    QString a_Name();
    void set_a_Name(QString a_Name);

    QString d_Date();
    void set_d_Date(QString d_Date);

signals:

};

#endif // BACKEND_H
