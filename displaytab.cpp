#include "displaytab.h"
#include "ui_displaytab.h"

DisplayTab::DisplayTab(QWidget *parent,Bibliotheque *Bib) :
    QMainWindow(parent),
    ui(new Ui::DisplayTab)
{
    ui->setupUi(this);
    this->Bib=Bib;
    this->setFixedSize(800,600);
    this->setWindowTitle("Affichage");
    this->setWindowIcon(QIcon(":/Icons/Afficher.png"));
    // Create a new model
   // QStandardItemModel(int rows, int columns, QObject * parent = 0)

   model1 = new QStandardItemModel(Bib->getIndiceLiv(),4,this);
   model1->setHeaderData(0, Qt::Horizontal, QObject::tr("Titre"));
   model1->setHeaderData(1, Qt::Horizontal, QObject::tr("Code"));
   model1->setHeaderData(2, Qt::Horizontal, QObject::tr("Quantite"));
   model1->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));

   ui->tableView1->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode(QHeaderView::Stretch));
   // Attach the model to the view
   ui->tableView1->setModel(model1);

   // Generate data

   for(int row = 0; row < Bib->getIndiceLiv(); row++)
   {
       for(int col = 0; col < 4; col++)
       {
           QModelIndex index= model1->index(row,col,QModelIndex());
           if(col==0)
                model1->setData(index,QString::fromStdString(Bib->getLiv()[row].getTitre()));
           if(col==1)
                model1->setData(index,Bib->getLiv()[row].getCode());
           if(col==2)
                model1->setData(index,Bib->getLiv()[row].getQuantite());
           if(col==3)
           {
               int jj=Bib->getLiv()[row].getDate().getJour(),mm=Bib->getLiv()[row].getDate().getMois(),aa=Bib->getLiv()[row].getDate().getAnne();
               QString date=QString::number(jj)+"/"+QString::number(mm)+"/"+QString::number(aa);

               model1->setData(index,date);
           }

       }
   }


   model2 = new QStandardItemModel(Bib->getIndiceEtu(),3,this);
   model2->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
   model2->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
   model2->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));

   ui->tableView2->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode(QHeaderView::Stretch));


   // Attach the model to the view
   ui->tableView2->setModel(model2);

   // Generate data

   for(int row = 0; row < Bib->getIndiceEtu(); row++)
   {
       for(int col = 0; col < 3; col++)
       {
           QModelIndex index= model2->index(row,col,QModelIndex());
           if(col==0)
                model2->setData(index,QString::fromStdString(Bib->getEtu()[row].getNom()));
           if(col==1)
                model2->setData(index,QString::fromStdString(Bib->getEtu()[row].getPrenom()));
           if(col==2)
                model2->setData(index,QString::fromStdString(Bib->getEtu()[row].getCIN()));


       }
   }


   model3 = new QStandardItemModel(Bib->getIndiceEns(),3,this);
   model3->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
   model3->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
   model3->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));

   ui->tableView3->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode(QHeaderView::Stretch));


   // Attach the model to the view
   ui->tableView3->setModel(model3);

   // Generate data

   for(int row = 0; row < Bib->getIndiceEns(); row++)
   {
       for(int col = 0; col < 3; col++)
       {
           QModelIndex index= model3->index(row,col,QModelIndex());
           if(col==0)
                model3->setData(index,QString::fromStdString(Bib->getEns()[row].getNom()));
           if(col==1)
                model3->setData(index,QString::fromStdString(Bib->getEns()[row].getPrenom()));
           if(col==2)
                model3->setData(index,QString::fromStdString(Bib->getEns()[row].getCIN()));


       }
   }
}
DisplayTab::~DisplayTab()
{
    delete ui;
}

void DisplayTab::on_Tab_tabCloseRequested(int index)
{
    ui->Tab->removeTab(index);
}

