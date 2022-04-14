#include "backend.h"

BackEnd::BackEnd(QObject *parent) : QAbstractListModel(parent), m_count(0)
{

}

//void BackEnd::registerTypes(const char *uri)
//{
//    qmlRegisterType<BackEnd>(uri, 1, 0, "BackEnd");
//}

int BackEnd::count() const
{
    return m_data.count();
}

int BackEnd::rowCount(const QModelIndex &p) const
{
    Q_UNUSED(p)
    return m_data.size();
}

QVariant BackEnd::data(const QModelIndex &index, int role) const
{
    Q_UNUSED(role)
    return QVariant::fromValue(m_data[index.row()]);
}

QHash<int, QByteArray> BackEnd::roleNames() const {
    static QHash<int, QByteArray> *roles;
    if (!roles) {
        roles = new QHash<int, QByteArray>;
        (*roles)[Qt::UserRole + 1] = "dataObject";
    }
    return *roles;
}

void BackEnd::append(QObject *o)
{
    int i = m_data.size();
    beginInsertRows(QModelIndex(), i, i);
    m_data.append(o);

    // Emit changed signals
    emit countChanged(count());

    endInsertRows();
}

void BackEnd::insert(QObject *o, int i)
{
    beginInsertRows(QModelIndex(), i, i);
    m_data.insert(i, o);
    o->setParent(this);

    // Emit changed signals
    emit countChanged(count());

    endInsertRows();
}

QObject* BackEnd::get(int i)
{
    Q_ASSERT(i >= 0 && i <= m_data.count());
    return m_data[i];
}

void BackEnd::backEndAppend(QQmlListProperty<QObject> *list, QObject *e)
{
    BackEnd *dom = qobject_cast<BackEnd*>(list->object);
        if (dom && e) {
            dom->append(e);
        }
}

long long int BackEnd::backEndCount(QQmlListProperty<QObject> *list)
{
    BackEnd *dom = qobject_cast<BackEnd*>(list->object);
    if (dom) {
        return dom->m_data.count();
    }
    return 0;
}

QObject *BackEnd::backEndAt(QQmlListProperty<QObject> *list, long long int i)
{
    BackEnd *dom = qobject_cast<BackEnd*>(list->object);
    if (dom) {
        return dom->get(i);
    }
    return 0;
}

void BackEnd::backEndClear(QQmlListProperty<QObject> *list)
{
    BackEnd *dom = qobject_cast<BackEnd*>(list->object);
    if (dom) {
        dom->m_data.clear();
    }
}

QQmlListProperty<QObject> BackEnd::content()
{
    return QQmlListProperty<QObject>(this, 0, &BackEnd::backEndAppend, &BackEnd::backEndCount,
 &BackEnd::backEndAt, &BackEnd::backEndClear);
}
