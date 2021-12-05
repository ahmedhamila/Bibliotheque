#ifndef ADDENSEIGNANT_H
#define ADDENSEIGNANT_H

#include <QMainWindow>
#include "Bibliotheque.h"
namespace Ui {
class addEnseignant;
}

class addEnseignant : public QMainWindow
{
    Q_OBJECT

public:
    explicit addEnseignant(QWidget *parent = nullptr,Bibliotheque *Bib=nullptr);
    ~addEnseignant();

private slots:
    void on_pushButton_clicked();

private:
    Ui::addEnseignant *ui;
    Bibliotheque *Bib;
};

#endif // ADDENSEIGNANT_H
