#ifndef MODIFYPROF_H
#define MODIFYPROF_H

#include <QMainWindow>
#include "Bibliotheque.h"
namespace Ui {
class ModifyProf;
}

class ModifyProf : public QMainWindow
{
    Q_OBJECT

public:
    explicit ModifyProf(QWidget *parent = nullptr,Bibliotheque *Bib=nullptr);
    ~ModifyProf();

private slots:
    void on_pushButton1_clicked();

    void on_pushButton2_clicked();

private:
    Ui::ModifyProf *ui;
    Bibliotheque *Bib;
};

#endif // MODIFYPROF_H
