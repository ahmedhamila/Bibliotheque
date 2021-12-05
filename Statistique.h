#include <iostream>
#pragma once
using namespace std;
#include "Bibliotheque.h"
class Statistique{
    public:
        static int nombreLivre(Bibliotheque);
        static int nombreEtudiant(Bibliotheque);
        static int nombreEnseignant(Bibliotheque);
};