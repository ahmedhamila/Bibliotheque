#include "mainwindow.h"

#include <QApplication>
#include <QMessageBox>
#include <QFile>
#include <QFileInfo>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile Fich1(QCoreApplication::applicationDirPath()+QString::fromStdString("/Arrays.csv"));
    if(!QFileInfo::exists(QCoreApplication::applicationDirPath()+QString::fromStdString("/Arrays.csv")))
        Fich1.open(QFile::WriteOnly |QFile::Text);
    QFile Fich2(QCoreApplication::applicationDirPath()+QString::fromStdString("/Livre.csv"));
    if(!QFileInfo::exists(QCoreApplication::applicationDirPath()+QString::fromStdString("/Livre.csv")))
        Fich2.open(QFile::WriteOnly |QFile::Text);
    QFile Fich3(QCoreApplication::applicationDirPath()+QString::fromStdString("/Etudiant.csv"));
    if(!QFileInfo::exists(QCoreApplication::applicationDirPath()+QString::fromStdString("/Etudiant.csv")))
        Fich3.open(QFile::WriteOnly |QFile::Text);
    QFile Fich4(QCoreApplication::applicationDirPath()+QString::fromStdString("/Enseignant.csv"));
    if(!QFileInfo::exists(QCoreApplication::applicationDirPath()+QString::fromStdString("/Enseignant.csv")))
        Fich4.open(QFile::WriteOnly |QFile::Text);
    QFile Fich5(QCoreApplication::applicationDirPath()+QString::fromStdString("/Emprunte.csv"));
    if(!QFileInfo::exists(QCoreApplication::applicationDirPath()+QString::fromStdString("/Emprunte.csv")))
        Fich5.open(QFile::WriteOnly |QFile::Text);

    MainWindow w;
    w.show();
    return a.exec();
}
