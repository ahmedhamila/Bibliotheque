#ifndef DISPLAYSEARCH_H
#define DISPLAYSEARCH_H

#include <QMainWindow>
#include <QTableView>
#include <QItemDelegate>
#include <QStandardItemModel>
#include "Bibliotheque.h"
namespace Ui {
class DisplaySearch;
}

class DisplaySearch : public QMainWindow
{
    Q_OBJECT

public:
    explicit DisplaySearch(QWidget *parent = nullptr,Bibliotheque *Bib=nullptr,int type =0,string *tit=nullptr,int code=0,string *cin=nullptr,string *nom=nullptr,string *prenom=nullptr);
    ~DisplaySearch();

private:
    Ui::DisplaySearch *ui;
    QStandardItemModel *model;
    Bibliotheque *Bib;
};

#endif // DISPLAYSEARCH_H
