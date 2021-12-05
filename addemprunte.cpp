#include "addemprunte.h"
#include "ui_addemprunte.h"
#include <QMessageBox>
AddEmprunte::AddEmprunte(QWidget *parent,Bibliotheque *Bib) :
    QMainWindow(parent),
    ui(new Ui::AddEmprunte)
{
    ui->setupUi(this);
    this->Bib=Bib;
    this->setFixedSize(800,600);
    this->setWindowTitle("Emprunte");
    this->setWindowIcon(QIcon(":/Icons/Emprunte.png"));

    ui->comboBox1->setVisible(false);
    ui->comboBox2->setVisible(false);
    ui->comboBox3->setVisible(false);
    ui->comboBox4->setVisible(false);

    for(int i=0;i<Bib->getIndiceEns();i++)
        ui->comboBox1->addItem(QString::fromStdString(Bib->getEns()[i].getNom())+" "+QString::fromStdString(Bib->getEns()[i].getPrenom()));
    for(int i=0;i<Bib->getIndiceEtu();i++)
        ui->comboBox3->addItem(QString::fromStdString(Bib->getEtu()[i].getNom())+" "+QString::fromStdString(Bib->getEtu()[i].getPrenom()));
    for(int i=0;i<Bib->getIndiceLiv();i++)
    {
        ui->comboBox2->addItem(QString::fromStdString(Bib->getLiv()[i].getTitre()));
        ui->comboBox4->addItem(QString::fromStdString(Bib->getLiv()[i].getTitre()));
    }
}

AddEmprunte::~AddEmprunte()
{
    delete ui;
}
bool  NumericStringEE(string str)
{
    int i=0;
    while(i<(int)str.length() && (str[i]>='0' && str[i]<='9' ))
        i++;
    if(i!=(int)str.length())
        return false;
    else
        return true;
}
bool AlphaStringEE(string str)
{
    int i=0;
    while(i<(int)str.length() && ((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z')))
        i++;
    if(i!=(int)str.length())
        return false;
    else
        return true;
}
void AddEmprunte::on_pushButton_clicked()
{
    string Nom,Prenom,Title;
    if(ui->radioButton1->isChecked())
    {
        QString Ens=ui->comboBox1->currentText();
        char nom[50];
        char prenom[50];
        int i,j;
        for( i=0;Ens[i]!=' ';i++)
            nom[i]=Ens[i].toLatin1();
        nom[i]='\0';
        i++;
        for( j=0;i<Ens.length();i++,j++)
        {
            prenom[j]=Ens[i].toLatin1();
        }

        prenom[j]='\0';
        Nom=nom;
        Prenom=prenom;
        Title=ui->comboBox2->currentText().toStdString();

        if(Bib->getLiv()[Bib->RechercheLivreIndex(Title)].getQuantite()>=1)
        {
            Bib->EmprunterEnseignant(Bib->RechercheEnseignantIndex(Nom,Prenom),Bib->RechercheLivreIndex(Title));
            QMessageBox msgBox;
            msgBox.setText("Emprunte Ajouté Avec Succés");
            msgBox.setWindowIcon(QIcon(":/Icons/Success.png"));
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setWindowTitle("Success");
            msgBox.setDefaultButton(QMessageBox::Ok);
            msgBox.setStyleSheet("background-color:#C4B6B6;");
            msgBox.exec();

            this->hide();
        }
        else
        {
            QMessageBox msgBox;
            msgBox.setText("Quantitée Insuffisante De Livre !");
            msgBox.setWindowIcon(QIcon(":/Icons/Warning.png"));
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle("Warning");
            msgBox.setDefaultButton(QMessageBox::Ok);
            msgBox.setStyleSheet("background-color:#C4B6B6;");
            msgBox.exec();
            return;
        }



    }
    else if(ui->radioButton2->isChecked())
    {

        QString Etu=ui->comboBox3->currentText();
        char nom[50];
        char prenom[50];
        int i,j;
        for( i=0;Etu[i]!=' ';i++)
            nom[i]=Etu[i].toLatin1();
        nom[i]='\0';
        i++;
        for( j=0;i<Etu.length();j++,i++)
            prenom[j]=Etu[i].toLatin1();
        prenom[j]='\0';
        Nom=nom;
        Prenom=prenom;

        Title=ui->comboBox4->currentText().toStdString();


        if(Bib->getLiv()[Bib->RechercheLivreIndex(Title)].getQuantite()>=1)
        {
            Bib->EmprunterEtudiant(Bib->RechercheEtudiantIndex(Nom,Prenom),Bib->RechercheLivreIndex(Title));
            QMessageBox msgBox;
            msgBox.setText("Emprunte Ajouté Avec Succés");
            msgBox.setWindowIcon(QIcon(":/Icons/Success.png"));
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setWindowTitle("Success");
            msgBox.setDefaultButton(QMessageBox::Ok);
            msgBox.setStyleSheet("background-color:#C4B6B6;");
            msgBox.exec();

            this->hide();
        }
        else
        {
            QMessageBox msgBox;
            msgBox.setText("Quantitée Insuffisante De Livre !");
            msgBox.setWindowIcon(QIcon(":/Icons/Warning.png"));
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle("Warning");
            msgBox.setDefaultButton(QMessageBox::Ok);
            msgBox.setStyleSheet("background-color:#C4B6B6;");
            msgBox.exec();
            return;
        }
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Il Faut Cocher Une Case !");
        msgBox.setWindowIcon(QIcon(":/Icons/Warning.png"));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Warning");
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.setStyleSheet("background-color:#C4B6B6;");
        msgBox.exec();
        return;
    }
    Bib->saveBibliotheque();
}


void AddEmprunte::on_radioButton1_clicked()
{
    ui->comboBox1->setVisible(true);
    ui->comboBox2->setVisible(true);
    ui->comboBox3->setVisible(false);
    ui->comboBox4->setVisible(false);
}


void AddEmprunte::on_radioButton2_clicked()
{
    ui->comboBox1->setVisible(false);
    ui->comboBox2->setVisible(false);
    ui->comboBox3->setVisible(true);
    ui->comboBox4->setVisible(true);
}

