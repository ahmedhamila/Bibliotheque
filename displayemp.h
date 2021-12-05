#ifndef DISPLAYEMP_H
#define DISPLAYEMP_H

#include <QMainWindow>
#include <QTableView>
#include <QItemDelegate>
#include <QStandardItemModel>
#include "Bibliotheque.h"
namespace Ui {
class DisplayEmp;
}

class DisplayEmp : public QMainWindow
{
    Q_OBJECT

public:
    explicit DisplayEmp(QWidget *parent = nullptr,Bibliotheque *Bib=nullptr);
    ~DisplayEmp();

private:
    Ui::DisplayEmp *ui;
    QStandardItemModel *model;
    Bibliotheque *Bib;
};

#endif // DISPLAYEMP_H
