#include "modifyprof.h"
#include "ui_modifyprof.h"
#include <QMessageBox>
ModifyProf::ModifyProf(QWidget *parent,Bibliotheque * Bib) :
    QMainWindow(parent),
    ui(new Ui::ModifyProf)
{
    ui->setupUi(this);
    this->Bib=Bib;
    this->setFixedSize(800,600);
    this->setWindowTitle("Modification D'enseignant");
    this->setWindowIcon(QIcon(":/Icons/Mod-Prof.png"));
    ui->lineEdit1->setMaxLength(20);
    ui->lineEdit2->setMaxLength(20);
    ui->lineEdit3->setMaxLength(8);
    ui->lineEdit3->setInputMask("99999999");

    ui->lineEdit1->setDisabled(true);
    ui->lineEdit2->setDisabled(true);
}

ModifyProf::~ModifyProf()
{
    delete ui;
}
bool  NumericStringME(string str)
{
    int i=0;
    while(i<(int)str.length() && (str[i]>='0' && str[i]<='9' ))
        i++;
    if(i!=(int)str.length())
        return false;
    else
        return true;
}
bool AlphaStringME(string str)
{
    int i=0;
    while(i<(int)str.length() && ((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z')))
        i++;
    if(i!=(int)str.length())
        return false;
    else
        return true;
}

void ModifyProf::on_pushButton1_clicked()
{
    QString cin=ui->lineEdit3->text();
    string CIN;
    if(cin.length()==8 && NumericStringME(cin.toStdString()))
    {
        CIN=cin.toStdString();
    }

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
        ui->lineEdit1->setText("");
        return;
    }
    if(Bib->RechercheEnseignantIndex(CIN)>=0)
    {
        ui->lineEdit1->setDisabled(false);
        ui->lineEdit2->setDisabled(false);

        ui->lineEdit1->setText(QString::fromStdString(Bib->getEns()[Bib->RechercheEnseignantIndex(CIN)].getNom()));
        ui->lineEdit2->setText(QString::fromStdString(Bib->getEns()[Bib->RechercheEnseignantIndex(CIN)].getPrenom()));
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("L'Enseignant N'Existe Pas !");
        msgBox.setWindowIcon(QIcon(":/Icons/Warning.png"));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Warning");
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.setStyleSheet("background-color:#C4B6B6;");
        msgBox.exec();
        return;
    }
}


void ModifyProf::on_pushButton2_clicked()
{
    QString Name=ui->lineEdit1->text();
    QString Last=ui->lineEdit2->text();
    QString cin=ui->lineEdit3->text();

    string Nom,Prenom,CIN;

    if(Name.length()>0 && AlphaStringME(Name.toStdString()))
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
    if(Last.length()>0 && AlphaStringME(Last.toStdString()))
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
    if(cin.length()==8 && NumericStringME(cin.toStdString()))
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
    Bib->getEns()[Bib->RechercheEnseignantIndex(CIN)].setNom(Nom);
    Bib->getEns()[Bib->RechercheEnseignantIndex(CIN)].setPrenom(Prenom);
    QMessageBox msgBox;
    msgBox.setText("Enseignant Modifié Avec Succés");
    msgBox.setWindowIcon(QIcon(":/Icons/Success.png"));
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setWindowTitle("Success");
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.setStyleSheet("background-color:#C4B6B6;");
    msgBox.exec();



    this->hide();
}

