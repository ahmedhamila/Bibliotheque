#include <iostream>
using namespace std;
#include "Date.h"
#pragma once
class Livre{
private:
    int code;
    string titre;
    Date date;
    unsigned quantite;
public:
    Livre();
    Livre(string ,int ,Date,unsigned );
    Livre(Livre &);
    
    void afficheLivre();
    void setCode(int );
    void setDate(Date );
    void setTitre(string );
    void setQuantite(unsigned);
    int getCode();
    string getTitre();
    Date getDate();
    unsigned getQuantite();

    bool operator==(Livre& L)
        {
            if (code==L.code && titre==L.titre && date==L.date && quantite==L.quantite)
                return true;
            else 
                return false;
        }
    bool operator!=(Livre& L)
        {
            if (code!=L.code && titre!=L.titre && date!=L.date && quantite!=L.quantite)
                return true;
            else 
                return false;
        }
};