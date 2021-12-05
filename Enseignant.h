#include <iostream>
#include "Livre.h"
#include "Personne.h"
using namespace std;
#pragma once
class Enseignant:public Personne{   
    public:
        Enseignant();
        Enseignant(string,string,string);
        Enseignant(Enseignant &);

        void afficheEnseignant();

        bool operator==(Enseignant& E)
        {
            if (nom==E.nom && prenom==E.prenom && CIN==E.CIN)
                return true;
            else 
                return false;
        }
        bool operator!=(Enseignant& E)
        {
            if (nom!=E.nom && prenom!=E.prenom && CIN!=E.CIN)
                return true;
            else 
                return false;
        }
};