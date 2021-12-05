#include <iostream>
#include <stdio.h>
#include "Livre.h"
#include <string>
using namespace std;
Livre::Livre() 
{
}
Livre::Livre(string tit,int co,Date d,unsigned q){
    titre=tit;
    code=co;
    date=d;
    quantite=q;

}
Livre::Livre(Livre &L)
{
    code=L.code;
    titre=L.titre;
    date=L.date;
    quantite=L.quantite;
}



void Livre::setCode(int cd)
{
        code=cd;
}

void Livre::setDate(Date d)
{
    date=d;
}
void Livre::setTitre(string tit)
{
    titre=tit;
}
void Livre:: setQuantite(unsigned q)
{
    quantite=q;
}
unsigned Livre:: getQuantite()
{
    return quantite;
}
int Livre::getCode(){return code;}
string Livre::getTitre(){return titre;}
Date Livre::getDate(){return date;}
