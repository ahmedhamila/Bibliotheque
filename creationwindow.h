#ifndef CREATIONWINDOW_H
#define CREATIONWINDOW_H

#include <QMainWindow>

namespace Ui {
class CreationWindow;
}

class CreationWindow : public QMainWindow
{
    Q_OBJECT

public:
    int MaxL,MaxEt,MaxEn;
    bool charged;
    explicit CreationWindow(QWidget *parent = nullptr);
    ~CreationWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::CreationWindow *ui;
};

#endif // CREATIONWINDOW_H
