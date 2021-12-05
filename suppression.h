#ifndef SUPPRESSION_H
#define SUPPRESSION_H

#include <QMainWindow>
#include "Bibliotheque.h"
namespace Ui {
class Suppression;
}

class Suppression : public QMainWindow
{
    Q_OBJECT

public:
    explicit Suppression(QWidget *parent = nullptr,Bibliotheque *Bib=nullptr);
    ~Suppression();

private slots:
    void on_pushButton_clicked();

    void on_radioButton1_clicked();

    void on_radioButton2_clicked();

    void on_radioButton3_clicked();


private:
    Ui::Suppression *ui;
    Bibliotheque *Bib;
};

#endif // SUPPRESSION_H
