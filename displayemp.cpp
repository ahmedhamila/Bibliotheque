#include "displayemp.h"
#include "ui_displayemp.h"
#include <QFile>
#include <iostream>
#include <QMessageBox>
using namespace std;

void parseEmprunteD(string Line,string *type,string *nom,string *prenom,string *tit)
{
    if(Line.length()>1)
    {
        int i=0;
        int j=0;
        char str[50];
        while(Line[i]!=',')
        {
            str[j]=Line[i];
            i++;
            j++;
        }
        str[j]='\0';
        *type=str;
        i++;
        j=0;
        while(Line[i]!=',')
        {
            str[j]=Line[i];
            i++;
            j++;
        }
        str[j]='\0';
        *nom=str;
        i++;
        j=0;
        while(Line[i]!=',')
        {
            str[j]=Line[i];
            i++;
            j++;
        }
        str[j]='\0';
        *prenom=str;
        i++;
        j=0;
        while(i<(int)Line.length())
        {
            str[j]=Line[i];
            i++;
            j++;
        }
        str[j]='\0';
        *tit=str;
    }
}

DisplayEmp::DisplayEmp(QWidget *parent,Bibliotheque *Bib) :
    QMainWindow(parent),
    ui(new Ui::DisplayEmp)
{
    ui->setupUi(this);
    this->setFixedSize(800,600);
    this->setWindowTitle("Affichage Des Empruntes");
    this->setWindowIcon(QIcon(":/Icons/Affiche-Emprunte.png"));
    this->Bib=Bib;
    QFile Fich(QCoreApplication::applicationDirPath()+QString::fromStdString("/Emprunte.csv"));
    Fich.open(QFile::ReadOnly |QFile::Text);
    QTextStream File(&Fich);
    QString Line;
    int line_count=0;
    while(!File.atEnd())
    {
        Line=File.readLine();
        line_count++;
    }

    // Create a new model
   // QStandardItemModel(int rows, int columns, QObject * parent = 0)
   if(line_count>1)
   {
       model = new QStandardItemModel(line_count-1,4,this);
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Etudiant/Enseignat"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Livre_Emprunte"));

       ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode(QHeaderView::Stretch));


       // Attach the model to the view
       ui->tableView->setModel(model);

       // Generate data

       File.seek(SEEK_SET);
       Line=File.readLine();
       string type,n,p,t;
       for(int row = 0; row < line_count-1; row++)
       {
           Line=File.readLine();
           parseEmprunteD(Line.toStdString(),&type,&n,&p,&t);
           for(int col = 0; col < 4; col++)
           {
               QModelIndex index= model->index(row,col,QModelIndex());
               if(col==0)
                    model->setData(index,QString::fromStdString(type));
               if(col==1)
                    model->setData(index,QString::fromStdString(n));
               if(col==2)
                    model->setData(index,QString::fromStdString(p));
               if(col==3)
               {
                   model->setData(index,QString::fromStdString(t));
               }

           }
       }
   }
   else
   {
       QMessageBox msgBox;
       msgBox.setText("Pas D'Empruntes");
       msgBox.setWindowIcon(QIcon(":/Icons/Warning.png"));
       msgBox.setIcon(QMessageBox::Warning);
       msgBox.setWindowTitle("Warning");
       msgBox.setDefaultButton(QMessageBox::Ok);
       msgBox.setStyleSheet("background-color:#C4B6B6;");
       msgBox.exec();
   }


    Fich.close();

}

DisplayEmp::~DisplayEmp()
{
    delete ui;
}
