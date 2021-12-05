#include "searchprof.h"
#include "ui_searchprof.h"
#include "displaysearch.h"
#include <QMessageBox>
SearchProf::SearchProf(QWidget *parent,Bibliotheque *Bib) :
    QMainWindow(parent),
    ui(new Ui::SearchProf)
{
    this->Bib=Bib;
    ui->setupUi(this);
    this->setFixedSize(800,600);
    this->setWindowTitle("Recherche D'Enseignant");
    this->setWindowIcon(QIcon(":/Icons/Search-Prof.png"));

    ui->lineEdit1->setMaxLength(8);
    ui->lineEdit1->setPlaceholderText("CIN");
    ui->lineEdit2->setMaxLength(20);
    ui->lineEdit2->setPlaceholderText("Nom");
    ui->lineEdit3->setMaxLength(20);
    ui->lineEdit3->setPlaceholderText("Prenom");

    ui->lineEdit1->setVisible(false);
    ui->lineEdit2->setVisible(false);
    ui->lineEdit3->setVisible(false);
}

SearchProf::~SearchProf()
{
    delete ui;
}

bool  NumericStringSP(string str)
{
    int i=0;
    while(i<(int)str.length() && (str[i]>='0' && str[i]<='9' ))
        i++;
    if(i!=(int)str.length())
        return false;
    else
        return true;
}
bool AlphaStringSP(string str)
{
    int i=0;
    while(i<(int)str.length() && ((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z')))
        i++;
    if(i!=(int)str.length())
        return false;
    else
        return true;
}
void SearchProf::on_pushButton_clicked()
{
    string CIN,Nom,Prenom;
    if(ui->radioButton1->isChecked())
    {
        QString cin=ui->lineEdit1->text();
        if(cin.length()==8 && NumericStringSP(cin.toStdString()))
        {
            CIN=cin.toStdString();
            if(Bib->RechercheEnseignantIndex(CIN)>=0)
            {
                model = new QStandardItemModel(1,3,this);
                model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
                model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
                model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));

                ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode(QHeaderView::Stretch));


                // Attach the model to the view
                ui->tableView->setModel(model);

                // Generate data

                QModelIndex index= model->index(0,0,QModelIndex());
                model->setData(index,QString::fromStdString(Bib->getEns()[Bib->RechercheEnseignantIndex(CIN)].getNom()));
                index= model->index(0,1,QModelIndex());
                model->setData(index,QString::fromStdString(Bib->getEns()[Bib->RechercheEnseignantIndex(CIN)].getPrenom()));
                index= model->index(0,2,QModelIndex());
                model->setData(index,QString::fromStdString(Bib->getEns()[Bib->RechercheEnseignantIndex(CIN)].getCIN()));

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

                model->clear();
                return;
            }

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


    }
    else if(ui->radioButton2->isChecked())
    {
        QString Name=ui->lineEdit2->text();
        QString Last=ui->lineEdit3->text();
        if(Name.length()>0 && AlphaStringSP(Name.toStdString()) && Last.length()>0 && AlphaStringSP(Last.toStdString()))
        {
            Nom=Name.toStdString();
            Prenom=Last.toStdString();
            if(Bib->RechercheEnseignantIndex(Nom,Prenom)>=0)
            {
                model = new QStandardItemModel(1,3,this);
                model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
                model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
                model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));

                ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode(QHeaderView::Stretch));


                // Attach the model to the view
                ui->tableView->setModel(model);

                // Generate data

                QModelIndex index= model->index(0,0,QModelIndex());
                model->setData(index,QString::fromStdString(Bib->getEns()[Bib->RechercheEnseignantIndex(Nom,Prenom)].getNom()));
                index= model->index(0,1,QModelIndex());
                model->setData(index,QString::fromStdString(Bib->getEns()[Bib->RechercheEnseignantIndex(Nom,Prenom)].getPrenom()));
                index= model->index(0,2,QModelIndex());
                model->setData(index,QString::fromStdString(Bib->getEns()[Bib->RechercheEnseignantIndex(Nom,Prenom)].getCIN()));
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

                model->clear();
                return;
            }
        }

        else
        {
            if(!(Name.length()>0 && AlphaStringSP(Name.toStdString())))
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


void SearchProf::on_radioButton1_clicked()
{
    ui->lineEdit1->setVisible(true);
    ui->lineEdit2->setVisible(false);
    ui->lineEdit3->setVisible(false);
}


void SearchProf::on_radioButton2_clicked()
{
    ui->lineEdit1->setVisible(false);
    ui->lineEdit2->setVisible(true);
    ui->lineEdit3->setVisible(true);
}

