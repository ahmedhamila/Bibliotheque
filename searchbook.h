#ifndef SEARCHBOOK_H
#define SEARCHBOOK_H

#include <QMainWindow>
#include "Bibliotheque.h"
#include <QTableView>
#include <QItemDelegate>
#include <QStandardItemModel>
namespace Ui {
class SearchBook;
}

class SearchBook : public QMainWindow
{
    Q_OBJECT

public:
    explicit SearchBook(QWidget *parent = nullptr,Bibliotheque *Bib=nullptr);
    ~SearchBook();

private slots:
    void on_pushButton_clicked();

    void on_radioButton1_clicked();

    void on_radioButton2_clicked();

private:
    Ui::SearchBook *ui;
    Bibliotheque *Bib;
    QStandardItemModel *model;
};

#endif // SEARCHBOOK_H
