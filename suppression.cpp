#include "suppression.h"
#include "ui_suppression.h"
#include <QMessageBox>
Suppression::Suppression(QWidget *parent,Bibliotheque *Bib) :
    QMainWindow(parent),
    ui(new Ui::Suppression)
{
    ui->setupUi(this);
    this->Bib=Bib;
    this->setFixedSize(800,600);
    this->setWindowTitle("Suppression");
    this->setWindowIcon(QIcon(":/Icons/Suppression.png"));

    ui->lineEdit1->setMaxLength(25);
    ui->lineEdit1->setPlaceholderText("Titre");
    ui->lineEdit1->setVisible(false);
    ui->lineEdit2->setMaxLength(20);
    ui->lineEdit2->setPlaceholderText("Nom");
    ui->lineEdit2->setVisible(false);
    ui->lineEdit3->setMaxLength(20);
    ui->lineEdit3->setPlaceholderText("Prenom");
    ui->lineEdit3->setVisible(false);
    ui->lineEdit4->setMaxLength(20);
    ui->lineEdit4->setPlaceholderText("Nom");
    ui->lineEdit4->setVisible(false);
    ui->lineEdit5->setMaxLength(20);
    ui->lineEdit5->setPlaceholderText("Prenom");
    ui->lineEdit5->setVisible(false);
}

Suppression::~Suppression()
{
    delete ui;
}
bool  NumericStringSU(string str)
{
    int i=0;
    while(i<(int)str.length() && (str[i]>='0' && str[i]<='9' ))
        i++;
    if(i!=(int)str.length())
        return false;
    else
        return true;
}
bool AlphaStringSU(string str)
{
    int i=0;
    while(i<(int)str.length() && ((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z')))
        i++;
    if(i!=(int)str.length())
        return false;
    else
        return true;
}
void Suppression::on_pushButton_clicked()
{
    string Title,Nom,Prenom;
    if(ui->radioButton1->isChecked())
    {
        QString Titre=ui->lineEdit1->text();
        if(Titre.length()>0)
        {
            Title=Titre.toStdString();
        }

        else
        {
            QMessageBox msgBox;
            msgBox.setText("Titre Invalide !");
            msgBox.setWindowIcon(QIcon(":/Icons/Warning.png"));
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle("Warning");
            msgBox.setDefaultButton(QMessageBox::Ok);
            msgBox.setStyleSheet("background-color:#C4B6B6;");
            msgBox.exec();
            ui->lineEdit1->setText("");
            return;
        }
        if(Bib->getIndiceLiv()>0)
        {
            if(Bib->SupprimerLivre(Title))
            {
                QMessageBox msgBox;
                msgBox.setText("Suppression Effectué Avec Succés");
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
                msgBox.setText("Livre n'Existe Pas !");
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
            msgBox.setText("Pas De Livre !");
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
        QString Name=ui->lineEdit2->text();
        if(Name.length()>0 && AlphaStringSU(Name.toStdString()))
        {
            Nom=Name.toStdString();
        }

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
            ui->lineEdit2->setText("");
            return;
        }
        QString Last=ui->lineEdit3->text();
        if(Last.length()>0&& AlphaStringSU(Last.toStdString()))
        {
            Prenom=Last.toStdString();
        }

        else
        {
            QMessageBox msgBox;
            msgBox.setText("Prenom Invalide !");
            msgBox.setWindowIcon(QIcon(":/Icons/Warning.png"));
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle("Warning");
            msgBox.setDefaultButton(QMessageBox::Ok);
            msgBox.setStyleSheet("background-color:#C4B6B6;");
            msgBox.exec();
            ui->lineEdit3->setText("");
            return;
        }

        if(Bib->getIndiceEns()>0)
        {
            if(Bib->SupprimerEnseignant(Nom,Prenom))
            {
                QMessageBox msgBox;
                msgBox.setText("Suppression Effectué Avec Succés");
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
                msgBox.setText("Enseignant n'Existe Pas !");
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
            msgBox.setText("Pas D'Enseignant !");
            msgBox.setWindowIcon(QIcon(":/Icons/Warning.png"));
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle("Warning");
            msgBox.setDefaultButton(QMessageBox::Ok);
            msgBox.setStyleSheet("background-color:#C4B6B6;");
            msgBox.exec();
            return;
        }
    }
    else if(ui->radioButton3->isChecked())
    {
        QString Name=ui->lineEdit4->text();
        if(Name.length()>0 && AlphaStringSU(Name.toStdString()))
        {
            Nom=Name.toStdString();
        }

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
            ui->lineEdit4->setText("");
            return;
        }
        QString Last=ui->lineEdit5->text();
        if(Last.length()>0 && AlphaStringSU(Last.toStdString()))
        {
            Prenom=Last.toStdString();
        }

        else
        {
            QMessageBox msgBox;
            msgBox.setText("Prenom Invalide !");
            msgBox.setWindowIcon(QIcon(":/Icons/Warning.png"));
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle("Warning");
            msgBox.setDefaultButton(QMessageBox::Ok);
            msgBox.setStyleSheet("background-color:#C4B6B6;");
            msgBox.exec();
            ui->lineEdit5->setText("");
            return;
        }

        if(Bib->getIndiceEtu()>0)
        {
            if(Bib->SupprimerEtudiant(Nom,Prenom))
            {
                QMessageBox msgBox;
                msgBox.setText("Suppression Effectué Avec Succés");
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
                msgBox.setText("Etudiant n'Existe Pas !");
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
            msgBox.setText("Pas D'Etudiant !");
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
}


void Suppression::on_radioButton1_clicked()
{
    ui->lineEdit1->setVisible(true);
    ui->lineEdit2->setVisible(false);
    ui->lineEdit3->setVisible(false);
    ui->lineEdit4->setVisible(false);
    ui->lineEdit5->setVisible(false);
}


void Suppression::on_radioButton2_clicked()
{
    ui->lineEdit1->setVisible(false);
    ui->lineEdit2->setVisible(true);
    ui->lineEdit3->setVisible(true);
    ui->lineEdit4->setVisible(false);
    ui->lineEdit5->setVisible(false);
}


void Suppression::on_radioButton3_clicked()
{
    ui->lineEdit1->setVisible(false);
    ui->lineEdit2->setVisible(false);
    ui->lineEdit3->setVisible(false);
    ui->lineEdit4->setVisible(true);
    ui->lineEdit5->setVisible(true);
}




