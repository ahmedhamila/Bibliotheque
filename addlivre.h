#ifndef ADDLIVRE_H
#define ADDLIVRE_H
#include "Bibliotheque.h"
#include "Date.h"
#include <QMainWindow>

namespace Ui {
class AddLivre;
}

class AddLivre : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddLivre(QWidget *parent = nullptr,Bibliotheque *Bib=nullptr);
    ~AddLivre();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddLivre *ui;
    Bibliotheque *Bib;
};

#endif // ADDLIVRE_H
