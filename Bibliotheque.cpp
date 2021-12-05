#include <iostream>
#include <stdio.h>
#include <cstddef>
#include "Bibliotheque.h"
#include <fstream>
#include <string>
#include <QFile>
#include <QTextStream>
#include <QApplication>
using namespace std;


Bibliotheque::Bibliotheque(){
    My_Etu=new Etudiant[100];
    My_Liv=new Livre[100];
    My_Ens=new Enseignant[100];
    ind_ens=0;
    ind_etu=0;
    ind_liv=0;
    MAX_LIVRE=100;
    MAX_ETUDIANT=100;
    MAX_ENSEIGNANT=100;
}
Bibliotheque::Bibliotheque(int liv_size,int etu_size,int ens_size)
{
    My_Etu=new Etudiant[etu_size];
    My_Liv=new Livre[liv_size];
    My_Ens=new Enseignant[ens_size];
    ind_ens=0;
    ind_etu=0;
    ind_liv=0; 
    MAX_LIVRE=liv_size;
    MAX_ETUDIANT=etu_size;
    MAX_ENSEIGNANT=ens_size;  
}
Bibliotheque::Bibliotheque(Bibliotheque &B)
{
    My_Etu=new Etudiant[B.ind_etu];
    My_Liv=new Livre[B.ind_liv];
    My_Ens=new Enseignant[B.ind_ens];
    for(ind_liv=0;ind_liv<B.ind_liv;ind_liv++)
    {
        My_Liv[ind_liv]=B.My_Liv[B.ind_liv];
    }
    for(ind_etu=0;ind_etu<B.ind_etu;ind_etu++)
    {
        My_Etu[ind_etu]=B.My_Etu[B.ind_etu];
    }
    for(ind_ens=0;ind_ens<B.ind_ens;ind_ens++)
    {
        My_Ens[ind_ens]=B.My_Ens[B.ind_ens];
    }
    MAX_LIVRE=B.MAX_LIVRE;
    MAX_ETUDIANT=B.MAX_ETUDIANT;
    MAX_ENSEIGNANT=B.MAX_ENSEIGNANT;    
}
void Bibliotheque::setSize(int liv_size,int etu_size,int ens_size)
{
    My_Etu=new Etudiant[etu_size];
    My_Liv=new Livre[liv_size];
    My_Ens=new Enseignant[ens_size];
    ind_ens=0;
    ind_etu=0;
    ind_liv=0;
    MAX_LIVRE=liv_size;
    MAX_ETUDIANT=etu_size;
    MAX_ENSEIGNANT=ens_size;  
}
bool Bibliotheque::ajouterLivre(Livre L)
{
    if(ind_liv < MAX_LIVRE)
    {
        My_Liv[ind_liv]=L;
        ind_liv++;
        return true;
    }
    else
    {
        return false;
    }
}

/*void Bibliotheque :: afficheBibliotheque()
{
    QFile Fich1("C:/Users/ahmed/Desktop/MyWork/QtProject/Bibliotheque/Affiche.txt");
    Fich1.open(QFile::WriteOnly |QFile::Text);
    QTextStream File1(&Fich1);
    File1<<"\t\t   *************Bibliotheque*************\n"<<"\n";
    if(ind_liv>0)
    {
        File1<<"\t\t       ***** Liste des Livres : *****\n"<<"\n";
        File1<<"\n";
        File1<<"\t\tTitre";
        for(int j=0;j<(maxLengthLivreTitre()-5);j++)
            File1<<" ";
        File1<<"|Code";
        for(int j=0;j<(maxLengthLivreCode()-4);j++)
            File1<<" ";
        File1<<"|Quantite";
        for(int j=0;j<(maxLengthLivreCode()-8);j++)
            File1<<" ";
        File1<<"|Date Release";
        File1<<"\n";
        for(int i=0 ;i<ind_liv;i++)
        {
            File1<<"\t\t"<<QString::fromStdString(My_Liv[i].getTitre());
            for(int j=0;j<maxLengthLivreTitre()-((int)My_Liv[i].getTitre().length());j++)
                File1<<" ";
            File1<<"|"<<My_Liv[i].getCode();
            if(IntLength(IntLength(My_Liv[i].getCode()))>4)
                for(int j=0;j<maxLengthLivreCode()-(IntLength(My_Liv[i].getCode()));j++)
                    File1<<" ";
            else
                for(int j=0;j<4-IntLength(My_Liv[i].getCode());j++)
                    File1<<" ";
            File1<<"|"<<My_Liv[i].getQuantite();
            if((IntLength(My_Liv[i].getQuantite()))>8)
                for(int j=0;j<maxLengthLivreQuantite()-(IntLength(My_Liv[i].getQuantite()));j++)
                    File1<<" ";
            else
                for(int j=0;j<8-IntLength(My_Liv[i].getQuantite());j++)
                    File1<<" ";
            File1<<"|"<<My_Liv[i].getDate().getJour()<<"/"<<My_Liv[i].getDate().getMois()<<"/"<<My_Liv[i].getDate().getAnne()<<"\n";
        }
    }
    else
    {
        File1<<"Pas De Livres"<<"\n";
    }
    File1<<"\t\t*******************************************\n\n";
     if(ind_etu>0)
    {
        File1<<"\t\t     ***** Liste des Etudiants : *****\n"<<"\n";
        File1<<"\t\tNom";
        for(int j=0;j<(maxLengthEtudiantNom()-3);j++)
            File1<<" ";
        File1<<"|Prenom";
        for(int j=0;j<(maxLengthEtudiantPrenom()-6);j++)
            File1<<" ";
        File1<<"|CIN";
        File1<<"\n";
        for(int i=0 ;i<ind_etu;i++)
        {
            File1<<"\t\t"<<QString::fromStdString(My_Etu[i].getNom());
            if(((int)My_Etu[i].getNom().length())>3)
                for(int j=0;j<maxLengthEtudiantNom()-((int)My_Etu[i].getNom().length());j++)
                    File1<<" ";
            else
                for(int j=0;j<3-((int)My_Etu[i].getNom().length());j++)
                    File1<<" ";
            File1<<"|"<<QString::fromStdString(My_Etu[i].getPrenom());
            if(((int)My_Etu[i].getPrenom().length())>6)
                for(int j=0;j<maxLengthEtudiantPrenom()-((int)My_Etu[i].getPrenom().length());j++)
                    File1<<" ";
            else
                for(int j=0;j<6-((int)My_Etu[i].getPrenom().length());j++)
                    File1<<" ";
            File1<<"|"<<QString::fromStdString(My_Etu[i].getCIN());
            File1<<"\n";

        }
    }
    else
    {
        File1<<"Liste des Etudiants est vide!!"<<"\n";
    }
    File1<<"\t\t*******************************************\n";

    if(ind_ens>0)
    {
        File1<<"\t\t    ***** Liste des Enseignants : *****\n"<<"\n";
        File1<<"\t\tNom";
        for(int j=0;j<(maxLengthEnseignantNom()-3);j++)
            File1<<" ";
        File1<<"|Prenom";
        for(int j=0;j<(maxLengthEnseignantPrenom()-6);j++)
            File1<<" ";
        File1<<"|CIN";
        File1<<"\n";
        for(int i=0 ;i<ind_ens;i++)
        {
            File1<<"\t\t"<<QString::fromStdString(My_Ens[i].getNom());
            if(((int)My_Ens[i].getNom().length())>3)
                for(int j=0;j<maxLengthEnseignantNom()-((int)My_Ens[i].getNom().length());j++)
                    File1<<" ";
            else
                for(int j=0;j<(maxLengthEnseignantNom()-3)+3-((int)My_Ens[i].getNom().length());j++)
                    File1<<" ";
            File1<<"|"<<QString::fromStdString(My_Ens[i].getPrenom());
            if(((int)My_Ens[i].getPrenom().length())>6)
                for(int j=0;j<maxLengthEnseignantPrenom()-((int)My_Ens[i].getPrenom().length());j++)
                    File1<<" ";
            else
                for(int j=0;j<6-((int)My_Ens[i].getPrenom().length())+(maxLengthEnseignantPrenom()-6);j++)
                    File1<<" ";
            File1<<"|"<<QString::fromStdString(My_Ens[i].getCIN());
            File1<<"\n";
        }
    }
    else
    {
        File1<<"Liste des Enseignants est vide!!"<<"\n";
    }
    File1<<"\t\t*******************************************"<<"\n";
    File1<<"\t\t  **************************************\n"<<"\n";
}*/
bool Bibliotheque::ajouterEtudiant(Etudiant E)
{
    if(ind_etu < MAX_ETUDIANT)
    {  
        My_Etu[ind_etu]=E;
        ind_etu++;
        return true;
    }
    else
    {
        return false;
    }   
}
bool Bibliotheque::ajouterEnseignant(Enseignant E)
{
    if(ind_ens < MAX_ENSEIGNANT)
    {   
        My_Ens[ind_ens]=E;
        ind_ens++;
        return true;
    }
    else
    {
        return false;
    }   
}
Etudiant Bibliotheque:: RechercheEtudiant(string name,string last)
{
    if(ind_etu>0)
    {
        int i=0;
        while(i<ind_etu && (My_Etu[i].getNom()!=name || My_Etu[i].getPrenom()!=last))
            i++;
        if(i<ind_etu)
            return My_Etu[i];
    }
    else
        cout<<"Liste des Etudiants est vide !!"<<endl; 
    Etudiant e;
    return e;   
}
Etudiant Bibliotheque:: RechercheEtudiant(string cin)
{
    if(ind_etu>0)
    {
        int i=0;
        while(i<ind_etu && My_Etu[i].getCIN()!=cin)
            i++;
        if(i<ind_etu)
            return My_Etu[i];
    }
    else
        cout<<"Liste des Etudiants est vide !!"<<endl;
    Etudiant e;
    return e;
}

Enseignant Bibliotheque:: RechercheEnseignant(string name,string last)
{
    if(ind_ens>0)
    {
        int i=0;
        while(i<ind_ens && (My_Ens[i].getNom()!=name || My_Ens[i].getPrenom()!=last))
            i++;
        if(i<ind_ens)
            return My_Ens[i];
    }
    else
        cout<<"Liste des Enseignants est vide !!"<<endl;
    Enseignant e;
    return e;    
}
Enseignant Bibliotheque:: RechercheEnseignant(string cin)
{
    if(ind_ens>0)
    {
        int i=0;
        while(i<ind_ens && My_Ens[i].getCIN()!=cin)
            i++;
        if(i<ind_ens)
            return My_Ens[i];
    }
    else
        cout<<"Liste des Enseignants est vide !!"<<endl;
    Enseignant e;
    return e;
}

Livre Bibliotheque:: RechercheLivre(string titre)//par nom
{
    if(ind_liv>0)
    {
        int i=0;
        while(i<ind_liv && My_Liv[i].getTitre()!=titre)
            i++;
        if(i<ind_liv)
            return My_Liv[i];
    }
    else
        cout<<"Liste des Livres est vide !!"<<endl;
    Livre e;
    return e;
}    
Livre Bibliotheque:: RechercheLivre(int code)//par code
{
    if(ind_liv>0)
    {
        int i=0;
        while(i<ind_liv && My_Liv[i].getCode()!=code)
            i++;
        if(i<ind_liv)
            return My_Liv[i];
    }
    else
        cout<<"Liste des Livres est vide !!"<<endl;
    Livre e;
    return e;
}   
   
void Bibliotheque:: SupprimerLivre(Livre L)
{
    if(ind_liv>0)
    {
        bool found=false;
        for(int i=0;i<ind_liv;i++)
        {
            if(My_Liv[i]==L)
            {
                found=true;
                for(int j=i;j<ind_liv-1;j++)
                {
                    My_Liv[j]=My_Liv[j+1];
                }
                ind_liv--;
                break;
            }
        }
        if(!found)
            cout<<"Livre Not Found !!"<<endl;
        else
        {
            cout<<"Suppression Effectuee Avec Succes"<<endl;
        }
    }
    else
        cout<<"Liste des Livres est vide !!"<<endl;
}
bool Bibliotheque:: SupprimerLivre(string Titre)
{
    if(ind_liv == 1 && My_Liv[0].getTitre()==Titre)
    {
        ind_liv=0;
        return true;
    }
    else
    {
        bool found=false;
        for(int i=0;i<ind_liv;i++)
        {
            if(My_Liv[i].getTitre()==Titre)
            {
                found=true;
                for(int j=i;j<ind_liv-1;j++)
                {
                    My_Liv[j]=My_Liv[j+1];
                }
                ind_liv--;
                break;
            }
        }
        if(!found)
            return false;
        else
        {
            return true;
        }
    }

}
void Bibliotheque:: SupprimerEtudiant(Etudiant E)
{
    if(ind_etu>0)
    {
        bool found=false;
        for(int i=0;i<ind_etu;i++)
        {
            if(My_Etu[i]==E)
            {
                found=true;
                for(int j=i;j<ind_etu-1;j++)
                {
                    My_Etu[j]=My_Etu[j+1];
                }
                ind_etu--;
                break;
            }
        }
        if(!found)
            cout<<"Etudiant Not Found !!"<<endl;
        else
        {
            cout<<"Suppression Effectuee Avec Succes"<<endl;
        }
    }
    else
        cout<<"Liste des Etudiants est vide !!"<<endl;
}
bool Bibliotheque:: SupprimerEtudiant(string Nom,string Prenom)
{
    bool found=false;
    for(int i=0;i<ind_etu;i++)
    {
        if(My_Etu[i].getNom()==Nom && My_Etu[i].getPrenom()==Prenom)
        {
            found=true;
            for(int j=i;j<ind_etu-1;j++)
            {
                My_Etu[j]=My_Etu[j+1];
            }
            ind_etu--;
            break;
        }
    }
    if(!found)
       return false;
    else
    {
        return true;
    }
}
void Bibliotheque:: SupprimerEnseignant(Enseignant E)
{
    if(ind_ens>0)
    {
        bool found=false;
        for(int i=0;i<ind_ens;i++)
        {
            if(My_Ens[i]==E)
            {
                found=true;
                for(int j=i;j<ind_ens-1;j++)
                {
                    My_Ens[j]=My_Ens[j+1];
                }
                ind_ens--;
                break;
            }
        }
        if(!found)
            cout<<"Enseignant Not Found !!"<<endl;
        else
        {
            cout<<"Suppression Effectuee Avec Succes"<<endl;
        }
    }
    else
        cout<<"Liste des Enseignants est vide !!"<<endl;
    
    
}
bool Bibliotheque:: SupprimerEnseignant(string Nom,string Prenom)
{

    bool found=false;
    for(int i=0;i<ind_ens;i++)
    {
        if(My_Ens[i].getNom()==Nom && My_Ens[i].getPrenom()==Prenom)
        {
            found=true;
            for(int j=i;j<ind_ens-1;j++)
            {
                My_Ens[j]=My_Ens[j+1];
            }
            ind_ens--;
            break;
        }
    }
    if(!found)
        return false;
    else
    {
        return true;
    }


}
void Bibliotheque::EmprunterEtudiant(int E,int L)
{
    My_Etu[E].ajouterLivre(My_Liv[L]);
    My_Liv[L].setQuantite(My_Liv[L].getQuantite()-1);
}
void Bibliotheque::EmprunterEnseignant(int E,int L)
{
    My_Ens[E].ajouterLivre(My_Liv[L]);
    My_Liv[L].setQuantite(My_Liv[L].getQuantite()-1);
        
}

int Bibliotheque::RechercheEtudiantIndex(string name,string last)//par nom et prenom
{
    if(ind_etu>0)
        {
            int i=0;
            while(i<ind_etu && (My_Etu[i].getNom()!=name || My_Etu[i].getPrenom()!=last))
                i++;
            if(i<ind_etu)
                return i;
        }

        return -1;
}
int Bibliotheque::RechercheEtudiantIndex(string cin)//par cin
{
    if(ind_etu>0)
        {
            int i=0;
            while(i<ind_etu && My_Etu[i].getCIN()!=cin)
                i++;
            if(i<ind_etu)
                return i;
        }

        return -1;    
}

int Bibliotheque::RechercheLivreIndex(string titre)//par nom
{
    if(ind_liv>0)
    {
        int i=0;
        while(i<ind_liv && My_Liv[i].getTitre()!=titre)
            i++;
        if(i<ind_liv)
            return i;
    }

    return -1;
}
int Bibliotheque::RechercheLivreIndex(int code)//par code
{
    if(ind_liv>0)
    {
        int i=0;
        while(i<ind_liv && My_Liv[i].getCode()!=code)
            i++;
        if(i<ind_liv)
            return i;
    }

    return -1;
}
int Bibliotheque::RechercheLivreIndex(string titre,int code,Date date,int quant)//par tout les atts
{
    if(ind_liv>0)
    {
        int i=0;
        while(i<ind_liv &&(My_Liv[i].getTitre()!=titre || My_Liv[i].getCode()!=code || My_Liv[i].getDate()!=date || My_Liv[i].getQuantite()!=(unsigned)quant))
            i++;
        if(i<ind_liv)
            return i;
    }

    return -1;
}

int  Bibliotheque::RechercheEnseignantIndex(string name,string last)
{
    if(ind_ens>0)
        {
            int i=0;
            while(i<ind_ens && (My_Ens[i].getNom()!=name || My_Ens[i].getPrenom()!=last))
                i++;
            if(i<ind_ens)
                return i;
        }

    return -1;
}
int  Bibliotheque::RechercheEnseignantIndex(string cin)
{
    if(ind_ens>0)
        {
            int i=0;
            while(i<ind_ens && My_Ens[i].getCIN()!=cin)
                i++;
            if(i<ind_ens)
                return i;
        }

        return -1;
}

void Bibliotheque::saveBibliotheque()
{
    QFile Fich1(QCoreApplication::applicationDirPath()+QString::fromStdString("/Arrays.csv"));
    Fich1.open(QFile::WriteOnly |QFile::Text);
    QTextStream File1(&Fich1);
    File1<<MAX_LIVRE<<"\n";
    File1<<MAX_ETUDIANT<<"\n";
    File1<<MAX_ENSEIGNANT<<"\n";
    File1<<ind_liv<<"\n";
    File1<<ind_etu<<"\n";
    File1<<ind_ens<<"\n";
    Fich1.close();
    QFile Fich2(QCoreApplication::applicationDirPath()+QString::fromStdString("/Livre.csv"));
    Fich2.open(QFile::WriteOnly |QFile::Text);
    QTextStream File2(&Fich2);
    File2<<"Titre,Code,Quantite,Date"<<"\n";
    for(int i=0;i<ind_liv;i++)
    {
        File2<<QString::fromStdString(My_Liv[i].getTitre())<<","<<My_Liv[i].getCode()<<","<<My_Liv[i].getQuantite()<<","<<My_Liv[i].getDate().getJour()<<"/"<<My_Liv[i].getDate().getMois()<<"/"<<My_Liv[i].getDate().getAnne()<<"\n";
    }
    Fich2.close();
    QFile Fich3(QCoreApplication::applicationDirPath()+QString::fromStdString("/Etudiant.csv"));
    Fich3.open(QFile::WriteOnly |QFile::Text);
    QTextStream File3(&Fich3);
    File3<<"Nom,Prenom,CIN"<<"\n";
    for(int i=0;i<ind_etu;i++)
    {
        File3<<QString::fromStdString(My_Etu[i].getNom())<<","<<QString::fromStdString(My_Etu[i].getPrenom())<<","<<QString::fromStdString(My_Etu[i].getCIN())<<"\n";
    }
    Fich3.close();
    QFile Fich4(QCoreApplication::applicationDirPath()+QString::fromStdString("/Enseignant.csv"));
    Fich4.open(QFile::WriteOnly |QFile::Text);
    QTextStream File4(&Fich4);
    File4<<"Nom,Prenom,CIN"<<"\n";
    for(int i=0;i<ind_ens;i++)
    {
        File4<<QString::fromStdString(My_Ens[i].getNom())<<","<<QString::fromStdString(My_Ens[i].getPrenom())<<","<<QString::fromStdString(My_Ens[i].getCIN())<<"\n";
    }
    Fich4.close();
    QFile Fich5(QCoreApplication::applicationDirPath()+QString::fromStdString("/Emprunte.csv"));
    Fich5.open(QFile::WriteOnly |QFile::Text);
    QTextStream File5(&Fich5);
    File5<<"Etudiant/Enseignat,Nom,Prenom,Livre_Emprunte"<<"\n";
    for(int i=0;i<ind_etu;i++)
    {
        if(My_Etu[i].nombreLivre()>0)
        {
            for(int j=0;j<My_Etu[i].nombreLivre();j++)
            {
                File5<<"Etudiant,"<<QString::fromStdString(My_Etu[i].getNom())<<","<<QString::fromStdString(My_Etu[i].getPrenom())<<","<<QString::fromStdString(My_Etu[i].livreEmprunte()[j].getTitre())<<"\n";
            }
        }
    }
    for(int i=0;i<ind_ens;i++)
    {
        if(My_Ens[i].nombreLivre()>0)
        {
            for(int j=0;j<My_Ens[i].nombreLivre();j++)
            {
                File5<<"Enseignant,"<<QString::fromStdString(My_Ens[i].getNom())<<","<<QString::fromStdString(My_Ens[i].getPrenom())<<","<<QString::fromStdString(My_Ens[i].livreEmprunte()[j].getTitre())<<"\n";
            }
        }
    }
    Fich5.close();
}
void parseLivre(string Line,string* s,int *code,unsigned *quant,int *jj,int *mm,int *aa)
{
    if(Line.length()>1)
    {
        int i=0;
        int j=0;
        char str[50];
        while(Line[i]!=',')
        {
            str[j]=Line[i];
            i++;
            j++;
        }
        str[j]='\0';
        *s=str;
        i++;
        j=0;
        while(Line[i]!=',')
        {
            str[j]=Line[i];
            i++;
            j++;
        }
        str[j]='\0';
        *code=stoi(str);
        i++;
        j=0;
        while(Line[i]!=',')
        {
            str[j]=Line[i];
            i++;
            j++;
        }
        str[j]='\0';
        *quant=stoi(str);
        i++;
        j=0;
        while(Line[i]!='/')
        {
            str[j]=Line[i];
            i++;
            j++;
        }
        str[j]='\0';
        *jj=stoi(str);
        i++;
        j=0;
        while(Line[i]!='/')
        {
            str[j]=Line[i];
            i++;
            j++;
        }
        str[j]='\0';
        *mm=stoi(str);
        i++;
        j=0;
        while(i<(int)Line.length())
        {
            str[j]=Line[i];
            i++;
            j++;
        }
        str[j]='\0';
        *aa=stoi(str);

    }
}
void parseEtudiant(string Line,string *name,string *last ,string *cin)
{
    if(Line.length()>1)
    {
        int i=0;
        int j=0;
        char str[50];
        while(Line[i]!=',')
        {
            str[j]=Line[i];
            i++;
            j++;
        }
        str[j]='\0';
        *name=str;
        i++;
        j=0;
        while(Line[i]!=',')
        {
            str[j]=Line[i];
            i++;
            j++;
        }
        str[j]='\0';
        *last=str;
        i++;
        j=0;
        while(i<(int)Line.length())
        {
            str[j]=Line[i];
            i++;
            j++;
        }
        str[j]='\0';
        *cin=str;
    }

}
void parseEmprunte(string Line,string *type,string *nom,string *prenom,string *tit)
{
    if(Line.length()>1)
    {
        int i=0;
        int j=0;
        char str[50];
        while(Line[i]!=',')
        {
            str[j]=Line[i];
            i++;
            j++;
        }
        str[j]='\0';
        *type=str;
        i++;
        j=0;
        while(Line[i]!=',')
        {
            str[j]=Line[i];
            i++;
            j++;
        }
        str[j]='\0';
        *nom=str;
        i++;
        j=0;
        while(Line[i]!=',')
        {
            str[j]=Line[i];
            i++;
            j++;
        }
        str[j]='\0';
        *prenom=str;
        i++;
        j=0;
        while(i<(int)Line.length())
        {
            str[j]=Line[i];
            i++;
            j++;
        }
        str[j]='\0';
        *tit=str;
    }
}

void Bibliotheque::loadBibliotheque()
{
    ind_liv=0;
    ind_ens=0;
    ind_etu=0;

    QFile Fich1(QCoreApplication::applicationDirPath()+QString::fromStdString("/Arrays.csv"));
    Fich1.open(QFile::ReadOnly |QFile::Text);
    QTextStream File1(&Fich1);
    QString Line;
    Line=File1.readLine();
    MAX_LIVRE = stoi(Line.toStdString());
    Line=File1.readLine();
    MAX_ETUDIANT = stoi(Line.toStdString());
    Line=File1.readLine();
    MAX_ENSEIGNANT = stoi(Line.toStdString());

    My_Etu=new Etudiant[MAX_LIVRE];
    My_Liv=new Livre[MAX_ETUDIANT];
    My_Ens=new Enseignant[MAX_ENSEIGNANT];

    Line=File1.readLine();
    int nb_liv = stoi(Line.toStdString());
    Line=File1.readLine();
    int nb_etu = stoi(Line.toStdString());
    Line=File1.readLine();
    int nb_ens = stoi(Line.toStdString());
    Fich1.close();

    QFile Fich2(QCoreApplication::applicationDirPath()+QString::fromStdString("/Livre.csv"));
    Fich2.open(QFile::ReadOnly |QFile::Text);
    QTextStream File2(&Fich2);
    Line=File2.readLine();
    int i=0;
    string tit;
    int code,jj,mm,aa;
    unsigned quant;
    while(!File2.atEnd() && i<nb_liv)
    {
        Line=File2.readLine();
        parseLivre(Line.toStdString(),&tit,&code,&quant,&jj,&mm,&aa);
        Date D(jj,mm,aa);
        Livre L(tit,code,D,quant);
        this->ajouterLivre(L);
        i++;
    }
    Fich2.close();
    QFile Fich3(QCoreApplication::applicationDirPath()+QString::fromStdString("/Etudiant.csv"));
    Fich3.open(QFile::ReadOnly |QFile::Text);
    QTextStream File3(&Fich3);
    Line=File3.readLine();
    i=0;
    string name;
    string last;
    string cin;
    while(!File3.atEnd() && i<nb_etu)
    {
        Line=File3.readLine();
        parseEtudiant(Line.toStdString(),&name,&last,&cin);
        Etudiant E(name,last,cin);
        this->ajouterEtudiant(E);
        i++;
    }
    Fich3.close();
    QFile Fich4(QCoreApplication::applicationDirPath()+QString::fromStdString("/Enseignant.csv"));
    Fich4.open(QFile::ReadOnly |QFile::Text);
    QTextStream File4(&Fich4);
    Line=File4.readLine();
    i=0;
    while(!File4.atEnd() && i<nb_ens)
    {
        Line=File4.readLine();
        parseEtudiant(Line.toStdString(),&name,&last,&cin);
        Enseignant E(name,last,cin);
        this->ajouterEnseignant(E);
        i++;
    }
    Fich4.close();
    QFile Fich5(QCoreApplication::applicationDirPath()+QString::fromStdString("/Emprunte.csv"));
    Fich5.open(QFile::ReadOnly |QFile::Text);
    QTextStream File5(&Fich5);
    Line=File5.readLine();
    i=0;
    string type,n,p,t;
    while(!File5.atEnd())
    {
        Line=File5.readLine();
        parseEmprunte(Line.toStdString(),&type,&n,&p,&t);
        if(type=="Etudiant")
            this->EmprunterEtudiant(this->RechercheEtudiantIndex(n,p),this->RechercheLivreIndex(t));
        else if(type=="Enseignant")
            this->EmprunterEnseignant(this->RechercheEnseignantIndex(n,p),this->RechercheLivreIndex(t));

    }

    Fich5.close();
}
