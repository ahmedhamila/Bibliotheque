#include "creationwindow.h"
#include "ui_creationwindow.h"
#include <string>
#include <QMessageBox>
CreationWindow::CreationWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CreationWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800,600);
    charged=false;
}

CreationWindow::~CreationWindow()
{
    delete ui;
}
bool NumericStringC(std::string str)
{
    int i=0;
    while(i<(int)str.length() && (str[i]>='0' && str[i]<='9' ))
        i++;
    if(i!=(int)str.length())
        return false;
    else
        return true;
}
void CreationWindow::on_pushButton_clicked()
{
    QString LivreMax=ui->lineEdit1->text();
    QString EtudiantMax=ui->lineEdit2->text();
    QString EnseignantMax=ui->lineEdit3->text();
    if(LivreMax.length()>0 && EtudiantMax.length()>0 && EnseignantMax.length()>0 && NumericStringC( LivreMax.toStdString()) && NumericStringC(EtudiantMax.toStdString())&& NumericStringC(EnseignantMax.toStdString()))
    {
        MaxL=stoi(LivreMax.toStdString());
        MaxEt=stoi(EtudiantMax.toStdString());
        MaxEn=stoi(EnseignantMax.toStdString());
        charged=true;
    }
    else
    {
        QMessageBox::information(this,tr("Warning"),"Il faut donner des valeurs Numeriques");
        return;
    }
        this->hide();
}

