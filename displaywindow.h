#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H

#include <QMainWindow>
#include "Bibliotheque.h"
namespace Ui {
class displayWindow;
}

class displayWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit displayWindow(QWidget *parent = nullptr,Bibliotheque *Bib=nullptr);
    ~displayWindow();

private:
    Ui::displayWindow *ui;
    Bibliotheque *Bib;
};

#endif // DISPLAYWINDOW_H
