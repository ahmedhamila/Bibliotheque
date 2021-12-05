#include <iostream>
using namespace std;
#include "Date.h"
/*void Date::afficheDate()
{
    if(jour!=0 && mois!=0 && anne!=0)
        cout <<"Date [ Jour : "<<jour <<", Mois : "<<mois<<", Anne :"<<anne<<" ]"<<endl;
    else
        cout<<"Date Invalide"<<endl;
}*/

Date::Date(int jj,int mm,int aa){

        jour=jj;
        mois=mm;
        anne=aa;
    
}
Date::Date()
{
}
Date::Date(Date &D)
{
    jour=D.jour;
    mois=D.mois;
    anne=D.anne;
}

void Date:: setJour(int j)
{
    jour=j;
}
void Date:: setMois(int m)
{
    mois=m;
}
void Date:: setAnne(int a)
{
    anne=a;
}
int  Date::getJour()
{
    return jour;
}
int  Date::getMois()
{
    return mois;
}
int  Date::getAnne()
{
    return anne;
}


