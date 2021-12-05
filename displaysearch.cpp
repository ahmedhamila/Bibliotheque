#include "displaysearch.h"
#include "ui_displaysearch.h"

DisplaySearch::DisplaySearch(QWidget *parent,Bibliotheque *Bib,int type ,string *tit,int code,string *cin,string *nom,string *prenom) :
    QMainWindow(parent),
    ui(new Ui::DisplaySearch)
{
    ui->setupUi(this);
    this->setFixedSize(800,600);
    if(type == 1)//recherche livre par titre
    {
        string Titre=*tit;
        this->setWindowTitle("Recherche Livre");
        this->Bib=Bib;
        this->setWindowIcon(QIcon(":/Icons/Afficher.png"));
        // Create a new model
       // QStandardItemModel(int rows, int columns, QObject * parent = 0)

       model = new QStandardItemModel(1,4,this);
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Titre"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("Code"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("Quantite"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));

       ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode(QHeaderView::Stretch));


       // Attach the model to the view
       ui->tableView->setModel(model);
       // Generate data

        QModelIndex index= model->index(0,0,QModelIndex());

        model->setData(index,QString::fromStdString(Bib->getLiv()[Bib->RechercheLivreIndex(Titre)].getTitre()));
        index= model->index(0,1,QModelIndex());
        model->setData(index,Bib->getLiv()[Bib->RechercheLivreIndex(Titre)].getCode());
        index= model->index(0,2,QModelIndex());
        model->setData(index,Bib->getLiv()[Bib->RechercheLivreIndex(Titre)].getQuantite());
        index= model->index(0,3,QModelIndex());
        int jj=Bib->getLiv()[Bib->RechercheLivreIndex(Titre)].getDate().getJour(),mm=Bib->getLiv()[Bib->RechercheLivreIndex(Titre)].getDate().getMois(),aa=Bib->getLiv()[Bib->RechercheLivreIndex(Titre)].getDate().getAnne();
        QString date=QString::number(jj)+"/"+QString::number(mm)+"/"+QString::number(aa);

        model->setData(index,date);




    }
    if(type == 2)//recherche livre par code
    {
        int Code=code;
        this->setWindowTitle("Recherche Livre");
        this->Bib=Bib;
        this->setWindowIcon(QIcon(":/Icons/Afficher.png"));
        // Create a new model
       // QStandardItemModel(int rows, int columns, QObject * parent = 0)

       model = new QStandardItemModel(1,4,this);
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Titre"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("Code"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("Quantite"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));

       ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode(QHeaderView::Stretch));


       // Attach the model to the view
       ui->tableView->setModel(model);
       // Generate data

        QModelIndex index= model->index(0,0,QModelIndex());

        model->setData(index,QString::fromStdString(Bib->getLiv()[Bib->RechercheLivreIndex(Code)].getTitre()));
        index= model->index(0,1,QModelIndex());
        model->setData(index,Bib->getLiv()[Bib->RechercheLivreIndex(Code)].getCode());
        index= model->index(0,2,QModelIndex());
        model->setData(index,Bib->getLiv()[Bib->RechercheLivreIndex(Code)].getQuantite());
        index= model->index(0,3,QModelIndex());
        int jj=Bib->getLiv()[Bib->RechercheLivreIndex(Code)].getDate().getJour(),mm=Bib->getLiv()[Bib->RechercheLivreIndex(Code)].getDate().getMois(),aa=Bib->getLiv()[Bib->RechercheLivreIndex(Code)].getDate().getAnne();
        QString date=QString::number(jj)+"/"+QString::number(mm)+"/"+QString::number(aa);

        model->setData(index,date);




    }
    if(type==3)
    {
        string CIN=*cin;
        model = new QStandardItemModel(1,3,this);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));

        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode(QHeaderView::Stretch));


        // Attach the model to the view
        ui->tableView->setModel(model);

        // Generate data

        QModelIndex index= model->index(0,0,QModelIndex());
        model->setData(index,QString::fromStdString(Bib->getEtu()[Bib->RechercheEtudiantIndex(CIN)].getNom()));
        index= model->index(0,1,QModelIndex());
        model->setData(index,QString::fromStdString(Bib->getEtu()[Bib->RechercheEtudiantIndex(CIN)].getPrenom()));
        index= model->index(0,2,QModelIndex());
        model->setData(index,QString::fromStdString(Bib->getEtu()[Bib->RechercheEtudiantIndex(CIN)].getCIN()));




    }
    if(type==4)
    {
        string Nom=*nom;
        string Prenom=*prenom;
        model = new QStandardItemModel(1,3,this);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));

        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode(QHeaderView::Stretch));


        // Attach the model to the view
        ui->tableView->setModel(model);

        // Generate data

        QModelIndex index= model->index(0,0,QModelIndex());
        model->setData(index,QString::fromStdString(Bib->getEtu()[Bib->RechercheEtudiantIndex(Nom,Prenom)].getNom()));
        index= model->index(0,1,QModelIndex());
        model->setData(index,QString::fromStdString(Bib->getEtu()[Bib->RechercheEtudiantIndex(Nom,Prenom)].getPrenom()));
        index= model->index(0,2,QModelIndex());
        model->setData(index,QString::fromStdString(Bib->getEtu()[Bib->RechercheEtudiantIndex(Nom,Prenom)].getCIN()));




    }
    if(type==5)
    {
        string CIN=*cin;
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
    if(type==6)
    {
        string Nom=*nom;
        string Prenom=*prenom;
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

}

DisplaySearch::~DisplaySearch()
{
    delete ui;
}
