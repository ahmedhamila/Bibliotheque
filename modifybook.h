#ifndef MODIFYBOOK_H
#define MODIFYBOOK_H

#include <QMainWindow>
#include "Bibliotheque.h"
namespace Ui {
class ModifyBook;
}

class ModifyBook : public QMainWindow
{
    Q_OBJECT

public:
    explicit ModifyBook(QWidget *parent = nullptr,Bibliotheque *Bib=nullptr);
    ~ModifyBook();

private slots:

    void on_pushButton1_clicked();

    void on_pushButton2_clicked();

private:
    Ui::ModifyBook *ui;
    Bibliotheque *Bib;
};

#endif // MODIFYBOOK_H
