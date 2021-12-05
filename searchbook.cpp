#include "searchbook.h"
#include "ui_searchbook.h"
#include <QMessageBox>
#include <QString>
#include "displaysearch.h"
SearchBook::SearchBook(QWidget *parent,Bibliotheque *Bib) :
    QMainWindow(parent),
    ui(new Ui::SearchBook)
{
    this->Bib=Bib;
    ui->setupUi(this);
    this->setFixedSize(800,600);
    this->setWindowTitle("Recherche De Livre");
    this->setWindowIcon(QIcon(":/Icons/Search-Book.png"));

    ui->lineEdit1->setMaxLength(20);
    ui->lineEdit1->setPlaceholderText("Titre");
    ui->lineEdit2->setMaxLength(8);
    ui->lineEdit2->setPlaceholderText("Code");

    ui->lineEdit1->setVisible(false);
    ui->lineEdit2->setVisible(false);

}

SearchBook::~SearchBook()
{
    delete ui;
}
bool  NumericStringS(string str)
{
    int i=0;
    while(i<(int)str.length() && (str[i]>='0' && str[i]<='9' ))
        i++;
    if(i!=(int)str.length())
        return false;
    else
        return true;
}
void SearchBook::on_pushButton_clicked()
{
    string Title;
    int Code;
    if(ui->radioButton1->isChecked())
    {
        QString Titre=ui->lineEdit1->text();
        if(Titre.length()>0)
        {
            Title=Titre.toStdString();
            if(Bib->RechercheLivreIndex(Title)>=0)
            {
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

                 model->setData(index,QString::fromStdString(Bib->getLiv()[Bib->RechercheLivreIndex(Title)].getTitre()));
                 index= model->index(0,1,QModelIndex());
                 model->setData(index,Bib->getLiv()[Bib->RechercheLivreIndex(Title)].getCode());
                 index= model->index(0,2,QModelIndex());
                 model->setData(index,Bib->getLiv()[Bib->RechercheLivreIndex(Title)].getQuantite());
                 index= model->index(0,3,QModelIndex());
                 int jj=Bib->getLiv()[Bib->RechercheLivreIndex(Title)].getDate().getJour(),mm=Bib->getLiv()[Bib->RechercheLivreIndex(Title)].getDate().getMois(),aa=Bib->getLiv()[Bib->RechercheLivreIndex(Title)].getDate().getAnne();
                 QString date=QString::number(jj)+"/"+QString::number(mm)+"/"+QString::number(aa);

                 model->setData(index,date);

            }
            else
            {
                QMessageBox msgBox;
                msgBox.setText("Le Livre N'Existe Pas !");
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


    }
    else if(ui->radioButton2->isChecked())
    {
        QString code=ui->lineEdit2->text();
        if(code.length()>0 && NumericStringS(code.toStdString()))
        {
            Code=code.toInt();
            if(Bib->RechercheLivreIndex(Code)>=0)
            {
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
            else
            {
                QMessageBox msgBox;
                msgBox.setText("Le Livre N'Existe Pas !");
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
            msgBox.setText("Code Invalide (Numerique >0)!");
            msgBox.setWindowIcon(QIcon(":/Icons/Warning.png"));
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle("Warning");
            msgBox.setDefaultButton(QMessageBox::Ok);
            msgBox.setStyleSheet("background-color:#C4B6B6;");
            msgBox.exec();
            ui->lineEdit2->setText("");
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


void SearchBook::on_radioButton1_clicked()
{
    ui->lineEdit1->setVisible(true);
    ui->lineEdit2->setVisible(false);
}


void SearchBook::on_radioButton2_clicked()
{
    ui->lineEdit1->setVisible(false);
    ui->lineEdit2->setVisible(true);
}

