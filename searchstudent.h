#ifndef SEARCHSTUDENT_H
#define SEARCHSTUDENT_H

#include <QMainWindow>
#include "Bibliotheque.h"
#include <QTableView>
#include <QItemDelegate>
#include <QStandardItemModel>
namespace Ui {
class SearchStudent;
}

class SearchStudent : public QMainWindow
{
    Q_OBJECT

public:
    explicit SearchStudent(QWidget *parent = nullptr,Bibliotheque *Bib=nullptr);
    ~SearchStudent();

private slots:
    void on_pushButton_clicked();

    void on_radioButton1_clicked();

    void on_radioButton2_clicked();

private:
    Ui::SearchStudent *ui;
    QStandardItemModel *model;
    Bibliotheque *Bib;
};

#endif // SEARCHSTUDENT_H
