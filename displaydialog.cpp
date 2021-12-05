#include "displaydialog.h"
#include "ui_displaydialog.h"

DisplayDialog::DisplayDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DisplayDialog)
{

}

DisplayDialog::~DisplayDialog()
{
    delete ui;
}
