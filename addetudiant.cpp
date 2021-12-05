#include "addetudiant.h"
#include "ui_addetudiant.h"
#include <QMessageBox>
addEtudiant::addEtudiant(QWidget *parent,Bibliotheque *Bib) :
    QMainWindow(parent),
    ui(new Ui::addEtudiant)
{
    this->Bib=Bib;
    ui->setupUi(this);
    this->setFixedSize(800,600);
    this->setWindowTitle("Ajout D'étudiant");
    this->setWindowIcon(QIcon(":/Icons/Add-Student.png"));
    ui->lineEdit1->setMaxLength(20);
    ui->lineEdit2->setMaxLength(20);
    ui->lineEdit3->setMaxLength(8);
    ui->lineEdit3->setInputMask("99999999");
}

addEtudiant::~addEtudiant()
{
    delete ui;
}
bool  NumericStringE(string str)
{
    int i=0;
    while(i<(int)str.length() && (str[i]>='0' && str[i]<='9' ))
        i++;
    if(i!=(int)str.length())
        return false;
    else
        return true;
}
bool AlphaStringE(string str)
{
    int i=0;
    while(i<(int)str.length() && ((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z')))
        i++;
    if(i!=(int)str.length())
        return false;
    else
        return true;
}
void addEtudiant::on_pushButton_clicked()
{
    QString Name=ui->lineEdit1->text();
    QString Last=ui->lineEdit2->text();
    QString cin=ui->lineEdit3->text();

    string Nom,Prenom,CIN;

    if(Name.length()>0 && AlphaStringE(Name.toStdString()))
        Nom=Name.toStdString();
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Nom Invalide !");
        msgBox.setWindowIcon(QIcon(":/Icons/Warning.png"));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Warning");
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.setStyleSheet("background-color:#C4B6B6;");
        msgBox.exec();
        return;
    }
    if(Last.length()>0 && AlphaStringE(Last.toStdString()))
        Prenom=Last.toStdString();
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Prénom Invalide !");
        msgBox.setWindowIcon(QIcon(":/Icons/Warning.png"));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Warning");
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.setStyleSheet("background-color:#C4B6B6;");
        msgBox.exec();
        return;
    }
    if(cin.length()==8 && NumericStringE(cin.toStdString()))
        CIN=cin.toStdString();
    else
    {
        QMessageBox msgBox;
        msgBox.setText("CIN Invalide !");
        msgBox.setWindowIcon(QIcon(":/Icons/Warning.png"));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Warning");
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.setStyleSheet("background-color:#C4B6B6;");
        msgBox.exec();
        return;
    }
    if(Bib->RechercheEtudiantIndex(Nom,Prenom)>0)
    {
        QMessageBox msgBox;
        msgBox.setText("Etudiant Déja Existe !");
        msgBox.setWindowIcon(QIcon(":/Icons/Warning.png"));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Warning");
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.setStyleSheet("background-color:#C4B6B6;");
        msgBox.exec();
        return;
    }
    Etudiant E(Nom,Prenom,CIN);
    if(Bib->ajouterEtudiant(E))
    {
        QMessageBox msgBox;
        msgBox.setText("Ajout Effectué Avec Succés");
        msgBox.setWindowIcon(QIcon(":/Icons/Success.png"));
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setWindowTitle("Success");
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.setStyleSheet("background-color:#C4B6B6;");
        msgBox.exec();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Tableau Est Plein !");
        msgBox.setWindowIcon(QIcon(":/Icons/Warning.png"));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Warning");
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.setStyleSheet("background-color:#C4B6B6;");
        msgBox.exec();
        return;
    }



    this->hide();
}

