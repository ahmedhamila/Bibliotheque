#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPushButton>
#include <QMainWindow>
#include "creationwindow.h"
#include "displaywindow.h"
#include "addlivre.h"
#include "addetudiant.h"
#include "addenseignant.h"
#include "suppression.h"
#include "displaytab.h"
#include "searchbook.h"
#include "searchstudent.h"
#include "searchprof.h"
#include "displayemp.h"
#include "addemprunte.h"
#include "modifybook.h"
#include "modifystudent.h"
#include "modifyprof.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionQuitter_triggered();

    void on_actionCreer_Une_Bibliotheque_triggered();

    void on_actionSave_triggered();

    void on_actionLoad_triggered();

    void on_actionAfficher_La_Biblioth_que_triggered();

    void on_actionAjouter_Un_Livre_triggered();

    void on_actionAjouter_Un_Etudiant_triggered();

    void on_actionAjouter_Un_Enseignant_triggered();

    void on_actionSuppression_triggered();

    void on_actionRechercher_Un_Livre_triggered();

    void on_actionRechercher_Un_Etudiant_triggered();

    void on_actionRechercher_Un_Enseignant_triggered();



    void on_actionAfficher_Les_Empruntes_triggered();

    void on_actionEmprunter_triggered();

    void on_actionModifier_Un_Livre_triggered();

    void on_actionModifier_Un_Etudiant_triggered();

    void on_actionModifier_Un_Enseignant_triggered();

private:
    Ui::MainWindow *ui;
    CreationWindow *CRW;
    displayWindow *DW;
    AddLivre *AL;
    addEtudiant *AE;
    addEnseignant *AES;
    Suppression *SUP;
    DisplayTab *DT;
    SearchBook *SB;
    SearchStudent *SS;
    SearchProf *SP;
    DisplayEmp *DE;
    AddEmprunte *AEM;
    ModifyBook *MB;
    ModifyStudent *MS;
    ModifyProf *MP;
};
#endif // MAINWINDOW_H
