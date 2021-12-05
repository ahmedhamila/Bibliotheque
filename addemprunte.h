#ifndef ADDEMPRUNTE_H
#define ADDEMPRUNTE_H

#include <QMainWindow>
#include "Bibliotheque.h"
namespace Ui {
class AddEmprunte;
}

class AddEmprunte : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddEmprunte(QWidget *parent = nullptr,Bibliotheque *Bib=nullptr);
    ~AddEmprunte();

private slots:
    void on_pushButton_clicked();

    void on_radioButton1_clicked();

    void on_radioButton2_clicked();

private:
    Ui::AddEmprunte *ui;
    Bibliotheque *Bib;
};

#endif // ADDEMPRUNTE_H
