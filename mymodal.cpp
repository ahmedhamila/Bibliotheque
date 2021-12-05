#include "mymodal.h"

mymodal::mymodal(QObject *parent)
    : QAbstractTableModel(parent)
{
}

QVariant mymodal::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

int mymodal::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return 2;
}

int mymodal::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return 3;
}

QVariant mymodal::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    return QString("Row%1, Column%2")
                      .arg(index.row() + 1)
                      .arg(index.column() +1);
    return QVariant();
}
