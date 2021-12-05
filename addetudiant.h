#ifndef ADDETUDIANT_H
#define ADDETUDIANT_H

#include <QMainWindow>
#include "Bibliotheque.h"
namespace Ui {
class addEtudiant;
}

class addEtudiant : public QMainWindow
{
    Q_OBJECT

public:
    explicit addEtudiant(QWidget *parent = nullptr,Bibliotheque *Bib=nullptr);
    ~addEtudiant();

private slots:
    void on_pushButton_clicked();

private:
    Ui::addEtudiant *ui;
    Bibliotheque *Bib;
};

#endif // ADDETUDIANT_H
