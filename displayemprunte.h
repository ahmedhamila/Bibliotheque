#ifndef DISPLAYEMPRUNTE_H
#define DISPLAYEMPRUNTE_H

#include <QMainWindow>
#include <QTableView>
#include <QItemDelegate>
#include <QStandardItemModel>
namespace Ui {
class DisplayEmprunte;
}

class DisplayEmprunte : public QMainWindow
{
    Q_OBJECT

public:
    explicit DisplayEmprunte(QWidget *parent = nullptr);
    ~DisplayEmprunte();

private:
    Ui::DisplayEmprunte *ui;
    QStandardItemModel *model;
};

#endif // DISPLAYEMPRUNTE_H
