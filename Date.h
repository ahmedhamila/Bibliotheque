#pragma once
class Date{
    private:
        int jour;
        int mois;
        int anne;
    public:
        
        Date(int,int,int);
        Date();
        Date(Date &);
        
        void afficheDate();

        void setJour(int);
        void setMois(int);
        void setAnne(int);
        int getJour();
        int getMois();
        int getAnne();

        bool operator==(Date& D)
        {
            if (jour==D.jour && mois==D.mois && anne==D.anne )
                return true;
            else 
                return false;
        }
        bool operator!=(Date& D)
        {
            if (jour!=D.jour && mois!=D.mois && anne!=D.anne )
                return true;
            else 
                return false;
        }
};
