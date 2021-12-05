#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include "Bibliotheque.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include<QSlider>
#include <QIcon>
#include <QRect>
#include <QTableView>
#include <QFileInfo>
#include "mymodal.h"

Bibliotheque *Bib;
bool once=false;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->showMaximized();
    this->setWindowTitle("Gestion De Bibliothéque");
    this->setWindowIcon(QIcon(":/Icons/Bibliotheque.png"));



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionQuitter_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionCreer_Une_Bibliotheque_triggered()
{
    QFile File(QCoreApplication::applicationDirPath()+QString::fromStdString("/Arrays.csv"));
    File.open( QIODevice::WriteOnly|QIODevice::Append );
    if (File.pos() == 0)
    {
        if(!once)
        {

            CRW=new CreationWindow(this);
            CRW->show();
            if(CRW->charged)
            {
                Bib=new Bibliotheque(CRW->MaxL,CRW->MaxEt,CRW->MaxEn);
                Bib->setSize(CRW->MaxL,CRW->MaxEt,CRW->MaxEn);
            }

            else
            {
                Bib=new Bibliotheque();
                Bib->setSize(100,100,100);
            }

            once=true;
            Bib->saveBibliotheque();
        }
        else
        {
            QMessageBox msgBox;
            msgBox.setText("Bibliothéque Déja Crée");
            msgBox.setWindowIcon(QIcon(":/Icons/Warning.png"));
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle("Warning");
            msgBox.setDefaultButton(QMessageBox::Ok);
            msgBox.setStyleSheet("background-color:#C4B6B6;");
            msgBox.exec();
        }
    }
    else
    {
        if(!once)
        {
            QMessageBox msgBox;
            msgBox.setText("Il Faut Charger La Bibliothéque");
            msgBox.setWindowIcon(QIcon(":/Icons/Warning.png"));
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle("Warning");
            msgBox.setDefaultButton(QMessageBox::Ok);
            msgBox.setStyleSheet("background-color:#C4B6B6;");
            msgBox.exec();
        }
        else
        {
            QMessageBox msgBox;
            msgBox.setText("Bibliothéque Déja Crée");
            msgBox.setWindowIcon(QIcon(":/Icons/Warning.png"));
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle("Warning");
            msgBox.setDefaultButton(QMessageBox::Ok);
            msgBox.setStyleSheet("background-color:#C4B6B6;");
            msgBox.exec();
        }

    }




}


void MainWindow::on_actionSave_triggered()
{
    if(once)
        Bib->saveBibliotheque();
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Il Faut Charger La Bibliothéque");
        msgBox.setWindowIcon(QIcon(":/Icons/Warning.png"));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Warning");
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.setStyleSheet("background-color:#C4B6B6;");
        msgBox.exec();
    }

}


void MainWindow::on_actionLoad_triggered()
{
    QFile File(QCoreApplication::applicationDirPath()+QString::fromStdString("/Arrays.csv"));
    File.open( QIODevice::WriteOnly|QIODevice::Append );
    if (File.pos() == 0)
    {
        QMessageBox msgBox;
        msgBox.setText("Fichier Vide, Il Faut Creer Une Bibliothéque");
        msgBox.setWindowIcon(QIcon(":/Icons/Warning.png"));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Warning");
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.setStyleSheet("background-color:#C4B6B6;");
        msgBox.exec();
    }
    else
    {
        if(!once)
        {
            once=true;
            Bib=new Bibliotheque();
            Bib->loadBibliotheque();
        }
        else
        {
            QMessageBox msgBox;
            msgBox.setText("Bibliothéque Déja Crée");
            msgBox.setWindowIcon(QIcon(":/Icons/Warning.png"));
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle("Warning");
            msgBox.setDefaultButton(QMessageBox::Ok);
            msgBox.setStyleSheet("background-color:#C4B6B6;");
            msgBox.exec();
        }
    }
}


void MainWindow::on_actionAfficher_La_Biblioth_que_triggered()
{
    if(once)
    {
        DT=new DisplayTab(this,Bib);
        DT->show();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Il Faut Créer Une Bibliothéque");
        msgBox.setWindowIcon(QIcon(":/Icons/Warning.png"));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Warning");
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.setStyleSheet("background-color:#C4B6B6;");
        msgBox.exec();
    }


}


void MainWindow::on_actionAjouter_Un_Livre_triggered()
{
    if(once)
    {
        AL=new AddLivre(this,Bib);
        AL->show();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Il Faut Créer Une Bibliothéque");
        msgBox.setWindowIcon(QIcon(":/Icons/Warning.png"));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Warning");
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.setStyleSheet("background-color:#C4B6B6;");
        msgBox.exec();
    }
}





void MainWindow::on_actionAjouter_Un_Etudiant_triggered()
{
    if(once)
    {
        AE=new addEtudiant(this,Bib);
        AE->show();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Il Faut Créer Une Bibliothéque");
        msgBox.setWindowIcon(QIcon(":/Icons/Warning.png"));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Warning");
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.setStyleSheet("background-color:#C4B6B6;");
        msgBox.exec();
    }
}


void MainWindow::on_actionAjouter_Un_Enseignant_triggered()
{
    if(once)
    {
        AES=new addEnseignant(this,Bib);
        AES->show();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Il Faut Créer Une Bibliothéque");
        msgBox.setWindowIcon(QIcon(":/Icons/Warning.png"));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Warning");
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.setStyleSheet("background-color:#C4B6B6;");
        msgBox.exec();
    }
}


void MainWindow::on_actionSuppression_triggered()
{
    if(once)
    {
        SUP=new Suppression(this,Bib);
        SUP->show();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Il Faut Créer Une Bibliothéque");
        msgBox.setWindowIcon(QIcon(":/Icons/Warning.png"));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Warning");
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.setStyleSheet("background-color:#C4B6B6;");
        msgBox.exec();
    }
}


void MainWindow::on_actionRechercher_Un_Livre_triggered()
{
    if(once)
    {
        SB=new SearchBook(this,Bib);
        SB->show();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Il Faut Créer Une Bibliothéque");
        msgBox.setWindowIcon(QIcon(":/Icons/Warning.png"));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Warning");
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.setStyleSheet("background-color:#C4B6B6;");
        msgBox.exec();
    }
}


void MainWindow::on_actionRechercher_Un_Etudiant_triggered()
{
    if(once)
    {
        SS=new SearchStudent(this,Bib);
        SS->show();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Il Faut Créer Une Bibliothéque");
        msgBox.setWindowIcon(QIcon(":/Icons/Warning.png"));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Warning");
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.setStyleSheet("background-color:#C4B6B6;");
        msgBox.exec();
    }
}


void MainWindow::on_actionRechercher_Un_Enseignant_triggered()
{
    if(once)
    {
        SP=new SearchProf(this,Bib);
        SP->show();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Il Faut Créer Une Bibliothéque");
        msgBox.setWindowIcon(QIcon(":/Icons/Warning.png"));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Warning");
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.setStyleSheet("background-color:#C4B6B6;");
        msgBox.exec();
    }
}





void MainWindow::on_actionAfficher_Les_Empruntes_triggered()
{
    if(once)
    {
        Bib->saveBibliotheque();
        DE=new DisplayEmp(this);
        DE->show();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Il Faut Créer Une Bibliothéque");
        msgBox.setWindowIcon(QIcon(":/Icons/Warning.png"));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Warning");
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.setStyleSheet("background-color:#C4B6B6;");
        msgBox.exec();
    }
}


void MainWindow::on_actionEmprunter_triggered()
{
    if(once)
    {
        AEM=new AddEmprunte(this,Bib);
        AEM->show();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Il Faut Créer Une Bibliothéque");
        msgBox.setWindowIcon(QIcon(":/Icons/Warning.png"));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Warning");
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.setStyleSheet("background-color:#C4B6B6;");
        msgBox.exec();
    }
}


void MainWindow::on_actionModifier_Un_Livre_triggered()
{
    if(once)
    {
       MB=new ModifyBook(this,Bib);
       MB->show();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Il Faut Créer Une Bibliothéque");
        msgBox.setWindowIcon(QIcon(":/Icons/Warning.png"));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Warning");
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.setStyleSheet("background-color:#C4B6B6;");
        msgBox.exec();
    }
}


void MainWindow::on_actionModifier_Un_Etudiant_triggered()
{
    if(once)
    {
       MS=new ModifyStudent(this,Bib);
       MS->show();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Il Faut Créer Une Bibliothéque");
        msgBox.setWindowIcon(QIcon(":/Icons/Warning.png"));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Warning");
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.setStyleSheet("background-color:#C4B6B6;");
        msgBox.exec();
    }
}


void MainWindow::on_actionModifier_Un_Enseignant_triggered()
{
    if(once)
    {
       MP=new ModifyProf(this,Bib);
       MP->show();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Il Faut Créer Une Bibliothéque");
        msgBox.setWindowIcon(QIcon(":/Icons/Warning.png"));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Warning");
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.setStyleSheet("background-color:#C4B6B6;");
        msgBox.exec();
    }
}

