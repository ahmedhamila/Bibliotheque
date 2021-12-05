#include <iostream>
#include <string>
#include <stdio.h>
#include "Personne.h"
#define MAX_LIVRE 100
using namespace std;
Personne::Personne()
{
}
Personne::Personne(string name,string last,string cin)
{

    nom=name;
    prenom=last;
    CIN=cin;
    LivreEmprunte=new Livre[MAX_LIVRE];
    indLivre=0;
}
Personne::Personne(Personne &E)
{
    nom=E.nom;
    prenom=E.prenom;
    CIN=E.CIN;
    LivreEmprunte=new Livre[MAX_LIVRE];
    indLivre=0;
}
string Personne::getNom()
{
    return nom;
}
string Personne::getPrenom()
{
    return prenom;
}
string Personne::getCIN()
{
    return CIN;
}
void Personne:: setNom(string name)
{
    nom=name;
}
void Personne:: setPrenom(string last)
{
    prenom=last;
}
void Personne:: setCIN(string cin)
{
    CIN=cin;
}
/*void Personne::affichePersonne()
{
    if(nom.length()!=0 && prenom.length()!=0 && CIN.length()!=0)
        cout<<"Personne [ Nom : "<<nom<<", Prenom : "<<prenom<<", CIN : "<<CIN<<" ]"<<endl;
    else
        cout<<"Personne Existe Pas!"<<endl;
}*/


int Personne:: RechercheLivreIndex(string titre)//par nom
{
    if(indLivre>0)
    {
        int i=0;
        while(i<indLivre && LivreEmprunte[i].getTitre()!=titre)
            i++;
        if(i<indLivre)
            return i;
    }
    return -1;
}
void Personne::ajouterLivre(Livre L)
{
    LivreEmprunte[indLivre]=L;
    indLivre++;
}
void Personne::supprimerLivre(Livre L)
{
    if(indLivre>0)
    {
        bool found=false;
        for(int i=0;i<indLivre;i++)
        {
            if(LivreEmprunte[i]==L)
            {
                found=true;
                for(int j=i;j<indLivre-1;j++)
                {
                    LivreEmprunte[j]=LivreEmprunte[j+1];
                }
                indLivre--;
                break;
            }
        }
        if(!found)
            cout<<"Livre Not Found !!"<<endl;
    }
    else
        cout<<"Liste des Livres est vide !!"<<endl;
}

Livre* Personne:: livreEmprunte()
{
    return this->LivreEmprunte;
}
int Personne:: nombreLivre()
{
    return indLivre;
}
