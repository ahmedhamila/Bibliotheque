#include "modifybook.h"
#include "ui_modifybook.h"
#include <QMessageBox>
ModifyBook::ModifyBook(QWidget *parent,Bibliotheque *Bib) :
    QMainWindow(parent),
    ui(new Ui::ModifyBook)
{
    ui->setupUi(this);
    this->Bib=Bib;
    this->setFixedSize(800,600);
    this->setWindowTitle("Modification De Livre");
    this->setWindowIcon(QIcon(":/Icons/Mod-Book.png"));
    ui->lineEdit1->setMaxLength(20);


    ui->lineEdit2->setMaxLength(8);
    ui->lineEdit3->setMaxLength(8);
    ui->lineEdit4->setMaxLength(10);
    ui->lineEdit4->setInputMask("99/99/9999");

    ui->lineEdit2->setDisabled(true);
    ui->lineEdit3->setDisabled(true);
    ui->lineEdit4->setDisabled(true);

}

ModifyBook::~ModifyBook()
{
    delete ui;
}



void ModifyBook::on_pushButton1_clicked()
{
    QString Titre=ui->lineEdit1->text();
    string Title;
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
        return;
    }
    if(Bib->RechercheLivreIndex(Title)>=0)
    {
        ui->lineEdit2->setDisabled(false);
        ui->lineEdit3->setDisabled(false);
        ui->lineEdit4->setDisabled(false);

        ui->lineEdit2->setText(QString::number(Bib->getLiv()[Bib->RechercheLivreIndex(Title)].getCode()));
        ui->lineEdit3->setText(QString::number(Bib->getLiv()[Bib->RechercheLivreIndex(Title)].getQuantite()));
        ui->lineEdit4->setText(QString::number(Bib->getLiv()[Bib->RechercheLivreIndex(Title)].getDate().getJour())+'/'+QString::number(Bib->getLiv()[Bib->RechercheLivreIndex(Title)].getDate().getMois())+QString::number(Bib->getLiv()[Bib->RechercheLivreIndex(Title)].getDate().getAnne()));


    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Livre N'existe Pas!");
        msgBox.setWindowIcon(QIcon(":/Icons/Warning.png"));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Warning");
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.setStyleSheet("background-color:#C4B6B6;");
        msgBox.exec();
        ui->lineEdit2->setDisabled(true);
        ui->lineEdit3->setDisabled(true);
        ui->lineEdit4->setDisabled(true);
        return;
    }
}

bool  NumericStringM(string str)
{
    int i=0;
    while(i<(int)str.length() && (str[i]>='0' && str[i]<='9' ))
        i++;
    if(i!=(int)str.length())
        return false;
    else
        return true;
}
bool dateValideM(int jj,int mm,int aa)
{
    if(!(aa>=1900 && aa<=2021))
        return false;
    else
    {
        if(!(mm>=1 && mm<=12))
            return false;
        else
        {
            int max_jour;
            switch(mm)
            {
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:max_jour=31;break;
                case 2:(((aa % 4 == 0) && (aa % 100 != 0)) ||(aa % 400 == 0))?max_jour=29:max_jour=28;break;
                case 4:
                case 6:
                case 9:
                case 11:max_jour=30;break;
                default:return false;break;
            }
            if(!(jj>=1&&jj<=max_jour))
                return false;
            return true;
        }
    }



}
void ModifyBook::on_pushButton2_clicked()
{
    QString Titre=ui->lineEdit1->text();
    QString Code=ui->lineEdit2->text();
    QString Quantite=ui->lineEdit3->text();
    QString date=ui->lineEdit4->text();
    string Title;
    int code;
    unsigned quant;
    int jj,mm,aa;
    Date *D;
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
        return;
    }

    if(NumericStringM(Code.toStdString()) && Code.toInt()>0)
    {
        code=Code.toInt();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Code Invalide(Numerique >0) !");
        msgBox.setWindowIcon(QIcon(":/Icons/Warning.png"));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Warning");
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.setStyleSheet("background-color:#C4B6B6;");
        msgBox.exec();
        return;
    }

    if(NumericStringM(Quantite.toStdString()) && Quantite.toUInt()>0)
    {
        quant=Quantite.toUInt();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Quantite Invalide(Numerique >0) !");
        msgBox.setWindowIcon(QIcon(":/Icons/Warning.png"));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Warning");
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.setStyleSheet("background-color:#C4B6B6;");
        msgBox.exec();
        return;
    }
    char j[3],m[3],a[5];
    j[0]=date.toStdString()[0];
    j[1]=date.toStdString()[1];
    j[2]='\0';
    m[0]=date.toStdString()[3];
    m[1]=date.toStdString()[4];
    m[2]='\0';
    a[0]=date.toStdString()[6];
    a[1]=date.toStdString()[7];
    a[2]=date.toStdString()[8];
    a[3]=date.toStdString()[9];
    a[4]='\0';

    jj=atoi(j);
    mm=atoi(m);
    aa=atoi(a);
    if(dateValideM(jj,mm,aa))
    {
         D=new Date(jj,mm,aa);
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Date Invalide !");
        msgBox.setWindowIcon(QIcon(":/Icons/Warning.png"));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Warning");
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.setStyleSheet("background-color:#C4B6B6;");
        msgBox.exec();
        return;
    }

    Bib->getLiv()[Bib->RechercheLivreIndex(Title)].setCode(code);
    Bib->getLiv()[Bib->RechercheLivreIndex(Title)].setQuantite(quant);
    Bib->getLiv()[Bib->RechercheLivreIndex(Title)].setDate(*D);

    QMessageBox msgBox;
    msgBox.setText("Livre Modifié Avec Succés");
    msgBox.setWindowIcon(QIcon(":/Icons/Success.png"));
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setWindowTitle("Success");
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.setStyleSheet("background-color:#C4B6B6;");
    msgBox.exec();

    this->hide();
}

