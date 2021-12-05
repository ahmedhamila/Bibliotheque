#include <iostream>
using namespace std;
#include "Statistique.h"

int Statistique::nombreLivre(Bibliotheque B)
{
    int nombre=0;
    for (int i = 0; i < B.ind_liv; i++)
    {
        cout<<"----"<<B.My_Liv[i].getQuantite()<<endl;
        nombre+=B.My_Liv[i].getQuantite();
    }
    return nombre;    
}
int Statistique::nombreEtudiant(Bibliotheque B)
{
    return B.ind_etu;
}
int Statistique::nombreEnseignant(Bibliotheque B)
{
    return B.ind_ens;
}