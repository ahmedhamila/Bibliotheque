#include "addenseignant.h"
#include "ui_addenseignant.h"
#include <QMessageBox>
addEnseignant::addEnseignant(QWidget *parent,Bibliotheque *Bib) :
    QMainWindow(parent),
    ui(new Ui::addEnseignant)
{
    this->Bib=Bib;
    ui->setupUi(this);
    this->setFixedSize(800,600);
    this->setWindowTitle("Ajout D'enseignant");
    this->setWindowIcon(QIcon(":/Icons/Add-Prof.png"));
    ui->lineEdit1->setMaxLength(20);
    ui->lineEdit2->setMaxLength(20);
    ui->lineEdit3->setMaxLength(8);
    ui->lineEdit3->setInputMask("99999999");
}

addEnseignant::~addEnseignant()
{
    delete ui;
}
bool  NumericStringES(string str)
{
    int i=0;
    while(i<(int)str.length() && (str[i]>='0' && str[i]<='9' ))
        i++;
    if(i!=(int)str.length())
        return false;
    else
        return true;
}
bool AlphaStringES(string str)
{
    int i=0;
    while(i<(int)str.length() && ((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z')))
        i++;
    if(i!=(int)str.length())
        return false;
    else
        return true;
}
void addEnseignant::on_pushButton_clicked()
{
    QString Name=ui->lineEdit1->text();
    QString Last=ui->lineEdit2->text();
    QString cin=ui->lineEdit3->text();

    string Nom,Prenom,CIN;

    if(Name.length()>0 && AlphaStringES(Name.toStdString()))
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
    if(Last.length()>0 && AlphaStringES(Last.toStdString()))
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
    if(cin.length()==8 && NumericStringES(cin.toStdString()))
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
    if(Bib->RechercheEnseignantIndex(Nom,Prenom)>0)
    {
        QMessageBox msgBox;
        msgBox.setText("Enseignant Déja Existe !");
        msgBox.setWindowIcon(QIcon(":/Icons/Warning.png"));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Warning");
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.setStyleSheet("background-color:#C4B6B6;");
        msgBox.exec();
        return;
    }

    Enseignant E(Nom,Prenom,CIN);
    if(Bib->ajouterEnseignant(E))
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

