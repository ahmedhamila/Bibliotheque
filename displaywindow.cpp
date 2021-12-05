#include "displaywindow.h"
#include "ui_displaywindow.h"
#include <QFile>
#include <QTextStream>
displayWindow::displayWindow(QWidget *parent,Bibliotheque *Bib) :
    QMainWindow(parent),
    ui(new Ui::displayWindow)
{
    ui->setupUi(this);
    this->Bib=Bib;

    this->showMaximized();
    this->setWindowTitle("Affichage");
    this->setWindowIcon(QIcon("C:/Users/ahmed/Desktop/MyWork/QtProject/Bibliotheque/Afficher.png"));
    Bib->afficheBibliotheque();
    QFile Fich1("C:/Users/ahmed/Desktop/MyWork/QtProject/Bibliotheque/Affiche.txt");
    Fich1.open(QFile::ReadOnly |QFile::Text);
    QTextStream File1(&Fich1);
    ui->textBrowser->setText(File1.readAll());
    ui->textBrowser->selectAll();
    ui->textBrowser->setAlignment(Qt::AlignLeft);

}

displayWindow::~displayWindow()
{
    delete ui;
}
