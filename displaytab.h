#ifndef DISPLAYTAB_H
#define DISPLAYTAB_H

#include <QMainWindow>
#include <QTableView>
#include <QItemDelegate>
#include <QStandardItemModel>
#include "Bibliotheque.h"
namespace Ui {
class DisplayTab;
}

class DisplayTab : public QMainWindow
{
    Q_OBJECT

public:
    explicit DisplayTab(QWidget *parent = nullptr,Bibliotheque *Bib=nullptr);
    ~DisplayTab();

private slots:
    void on_Tab_tabCloseRequested(int index);

private:
    Ui::DisplayTab *ui;
    QStandardItemModel *model1;
    QStandardItemModel *model2;
    QStandardItemModel *model3;
    Bibliotheque *Bib;
    void onTableClicked(const QModelIndex &index);
};

#endif // DISPLAYTAB_H
