#ifndef SEARCHPROF_H
#define SEARCHPROF_H

#include <QMainWindow>
#include "Bibliotheque.h"
#include <QTableView>
#include <QItemDelegate>
#include <QStandardItemModel>
namespace Ui {
class SearchProf;
}

class SearchProf : public QMainWindow
{
    Q_OBJECT

public:
    explicit SearchProf(QWidget *parent = nullptr,Bibliotheque *Bib=nullptr);
    ~SearchProf();

private slots:
    void on_pushButton_clicked();

    void on_radioButton1_clicked();

    void on_radioButton2_clicked();

private:
    Ui::SearchProf *ui;
    Bibliotheque *Bib;
    QStandardItemModel *model;
};

#endif // SEARCHPROF_H
