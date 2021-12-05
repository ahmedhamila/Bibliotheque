#include <iostream>
#include "Livre.h"
#include "Etudiant.h"
#include "Enseignant.h"

#pragma once
using namespace std;
class Bibliotheque{
    private :
    Livre *My_Liv;
    Etudiant *My_Etu;
    Enseignant *My_Ens;
    int ind_ens;
    int ind_etu;
    int ind_liv;
    int MAX_LIVRE;
    int MAX_ETUDIANT;
    int MAX_ENSEIGNANT;

    public:
        Bibliotheque();
        Bibliotheque(int,int,int);
        Bibliotheque(Bibliotheque &);

        bool ajouterLivre(Livre);
        bool ajouterEtudiant(Etudiant);
        bool ajouterEnseignant(Enseignant E);

        void SupprimerLivre(Livre);
        bool SupprimerLivre(string );
        void SupprimerEtudiant(Etudiant);
        bool SupprimerEtudiant(string,string);
        void SupprimerEnseignant(Enseignant E);
        bool SupprimerEnseignant(string,string);

        Etudiant RechercheEtudiant(string,string);//par nom et prenom
        Etudiant RechercheEtudiant(string);//par cin
        
        Livre RechercheLivre(string);//par nom
        Livre RechercheLivre(int);//par code

        Enseignant  RechercheEnseignant(string name,string last);
        Enseignant  RechercheEnseignant(string cin);

        int RechercheEtudiantIndex(string,string);//par nom et prenom
        int RechercheEtudiantIndex(string);//par cin
        
        int RechercheLivreIndex(string);//par nom
        int RechercheLivreIndex(int);//par code
        int RechercheLivreIndex(string,int,Date,int);//par tout les atts

        int  RechercheEnseignantIndex(string name,string last);
        int  RechercheEnseignantIndex(string cin);
        
        

        void EmprunterEtudiant(int,int); 
        void EmprunterEnseignant(int,int);

        void setSize(int,int,int);
        

        void saveBibliotheque();
        void loadBibliotheque();

        Etudiant *getEtu()
        {
            return My_Etu;
        }
        Enseignant *getEns()
        {
            return My_Ens;
        }
        Livre *getLiv()
        {
            return My_Liv;
        }
        int getIndiceEtu(){return ind_etu;}
        int getIndiceEns(){return ind_ens;};
        int getIndiceLiv(){return ind_liv;};
        friend class Statistique;


        
};
