#include "procession.hpp"
#include "couleur.hpp"

#ifndef DEMONSTRATION_HPP
#define DEMONSTRATION_HPP

#include <vector>
#include <string>

/*
Demonstration = Manif est un Procession (Cortege) qui se déplace
*/

class Demonstration {
    private:
        int width;
        int length;
        Procession *procession;

        //Grille qui va servir de conteneur de personnes 
        //ou de pointeurs nuls quand la personne bouge
        std::vector<std::vector<Person *>> grid;
        int numPeople;

        //Variables permettant d'itérer selon un maximum qui varie
        //eg. au début parcours de 3 étudiant uniquement pour une 
        //grille 3x3 ensuite 6 etudiant puis 9 en fonction de simStage()
        int stageCount = 1;
        int stageCountMax;

        //Pour signaler le dépassement des id présent dans le cortège
        //et permettre de parcourir le reste de la grille 
        bool sig = false;

        //Se met a true quad la dernière rangée (du haut) est la seule
        //ou il y a des personnes présentes
        bool lastRowFlag = false;

    public:
        Demonstration(int wid, int len, Procession *proc);
        ~Demonstration();

        bool hasEnded() const;
        Person getPerson(int id);
        void removePerson(int id);
        std::vector<Person *> getLeaders() const;

        void updatePosition(int id);
        void simStage();
        void displayGrid();
};

#endif
