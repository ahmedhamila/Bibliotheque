#pragma once
#include <iostream>
using namespace std;
#include "Livre.h"
class Personne{
    protected:
        string nom;
        string prenom;
        string CIN;
        Livre *LivreEmprunte;
        int indLivre;
    public:
        Personne();
        Personne(string,string,string);
        Personne(Personne &);

        string getNom();
        string getPrenom();
        string getCIN();
        void setNom(string);
        void setPrenom(string);
        void setCIN(string);

        void affichePersonne();

        void ajouterLivre(Livre);
        void afficheLivreEmprunte();
        void supprimerLivre(Livre);
        int nombreLivre();
        int RechercheLivreIndex(string );
        Livre * livreEmprunte();

        bool operator==(Personne& E)
        {
            if (nom==E.nom && prenom==E.prenom && CIN==E.CIN)
                return true;
            else 
                return false;
        }
         bool operator!=(Personne& E)
        {
            if (nom!=E.nom && prenom!=E.prenom && CIN!=E.CIN)
                return true;
            else 
                return false;
        }
};