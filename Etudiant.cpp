#include <iostream>
#include <string>
#include <stdio.h>
#include "Etudiant.h"
#define MAX_LIVRE 10
using namespace std;

Etudiant::Etudiant()
{
}
Etudiant::Etudiant(string name,string last,string cin):Personne(name,last,cin)
{
    LivreEmprunte=new Livre[MAX_LIVRE];
    indLivre=0;
}
Etudiant::Etudiant(Etudiant &E): Personne(E)
{
    LivreEmprunte=new Livre[MAX_LIVRE];
    indLivre=0;
}
/*void Etudiant::afficheEtudiant()
{
    if(nom.length()!=0 && prenom.length()!=0 && CIN.length()!=0)
    {
        cout<<"Etudiant [ Nom : "<<nom<<", Prenom : "<<prenom<<", CIN : "<<CIN<<" ]"<<endl;
        if(indLivre>0)
        {
            cout<<"Livre Empruntee : "<<endl;
            for(int i=0;i<indLivre;i++)
            {
                cout<<"Livre [ Titre : "<<LivreEmprunte[i].getTitre()<<", Code : "<<LivreEmprunte[i].getCode()<<" ]"<<endl;
            }   
        }
        else
           cout<<"Pas De Livre Empruntee"<<endl;
    }
        
    else
        cout<<"Etudiant Existe Pas!"<<endl;
}*/
