#include <iostream>
#include <stdio.h>
#include <string>
#include "Enseignant.h"
#define MAX_LIVRE 10
using namespace std;
Enseignant::Enseignant()
{
}
Enseignant::Enseignant(string name,string last,string cin) : Personne(name,last,cin)
{
    LivreEmprunte=new Livre[MAX_LIVRE];
    indLivre=0;
}
Enseignant::Enseignant(Enseignant &E) : Personne(E)
{
    LivreEmprunte=new Livre[MAX_LIVRE];
    indLivre=0;
}

/*void Enseignant::afficheEnseignant()
{
    if(nom.length()!=0 && prenom.length()!=0 && CIN.length()!=0)
    {
        cout<<"Enseignant [ Nom : "<<nom<<", Prenom : "<<prenom<<", CIN : "<<CIN<<" ]"<<endl;
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
        cout<<"Enseignant Existe Pas!"<<endl;
}*/
