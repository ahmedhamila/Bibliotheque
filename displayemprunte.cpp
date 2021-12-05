#include "displayemprunte.h"
#include "ui_displayemprunte.h"
#include <QFile>
#include <QTextStream>
#include <iostream>
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
DisplayEmprunte::DisplayEmprunte(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DisplayEmprunte)
{
    ui->setupUi(this);
    this->setFixedSize(800,600);
    this->setWindowTitle("Affichage Des Empruntes");
    this->setWindowIcon(QIcon(":/Icons/Affiche-Emprunte.png"));
    // Create a new model
   // QStandardItemModel(int rows, int columns, QObject * parent = 0)
   ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode(QHeaderView::Stretch));


   // Attach the model to the view
   ui->tableView->setModel(model);
   // Generate data

   QFile Fich("C:/Users/ahmed/Desktop/MyWork/QtProject/Bibliotheque/Emprunte.csv");
   Fich.open(QFile::ReadOnly |QFile::Text);
   QTextStream File(&Fich);
   QString Line[100];
   int line_count=0;
   while( !File.atEnd())
   {
       Line[line_count]=File.readLine();
       cout<<Line[line_count].toStdString()<<"\n";
       line_count++;
   }
   model = new QStandardItemModel(line_count-1,4,this);

   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Etudiant/Enseignat"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("Livre_Emprunte"));

   string type,nom,prenom,titre;
   for(int row = 0; row < line_count-1; row++)
   {
       for(int col = 0; col < 4; col++)
       {
           QModelIndex index= model->index(row,col,QModelIndex());
           parseEmprunteD(Line[row+1].toStdString(),&type,&nom,&prenom,&titre);

           if(col==0)
           {
               if(type=="Etudiant")
                   model->setData(index,QString::fromStdString("Etudiant"));
               else if(type=="Enseignant")
                   model->setData(index,QString::fromStdString("Enseignant"));

           }

           if(col==1)
                model->setData(index,QString::fromStdString(nom));
           if(col==2)
                model->setData(index,QString::fromStdString(prenom));
           if(col==3)
           {
               model->setData(index,QString::fromStdString(titre));
           }

       }
   }
   Fich.close();
}

DisplayEmprunte::~DisplayEmprunte()
{
    delete ui;
}
