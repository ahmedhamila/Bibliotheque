#ifndef MODIFYSTUDENT_H
#define MODIFYSTUDENT_H

#include <QMainWindow>
#include "Bibliotheque.h"
namespace Ui {
class ModifyStudent;
}

class ModifyStudent : public QMainWindow
{
    Q_OBJECT

public:
    explicit ModifyStudent(QWidget *parent = nullptr,Bibliotheque *bib=nullptr);
    ~ModifyStudent();

private slots:
    void on_pushButton1_clicked();

    void on_pushButton2_clicked();

private:
    Ui::ModifyStudent *ui;
    Bibliotheque *Bib;
};

#endif // MODIFYSTUDENT_H
