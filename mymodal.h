#ifndef MYMODAL_H
#define MYMODAL_H

#include <QAbstractTableModel>

class mymodal : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit mymodal(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:

};

#endif // MYMODAL_H
