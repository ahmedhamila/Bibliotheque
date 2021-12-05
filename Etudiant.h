#include <iostream>
#include "Livre.h"
#include "Personne.h"
using namespace std;
#pragma once
class Etudiant:public Personne{      
    public:
        Etudiant();
        Etudiant(string,string,string);
        Etudiant(Etudiant &);

        void afficheEtudiant();
        bool operator==(Etudiant& E)
        {
            if (nom==E.nom && prenom==E.prenom && CIN==E.CIN)
                return true;
            else 
                return false;
        }
        bool operator!=(Etudiant& E)
        {
            if (nom!=E.nom && prenom!=E.prenom && CIN!=E.CIN)
                return true;
            else 
                return false;
        }
};