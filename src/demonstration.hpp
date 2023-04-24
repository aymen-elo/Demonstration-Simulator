#ifndef DEMONSTRATION_HPP
#define DEMONSTRATION_HPP
#include <vector>
#include <iostream>
#include "procession.hpp"

/*
Demonstration = Manif est un Procession (Cortege) qui se déplace
*/

class Demonstration {
    private:
        int width;
        int length;
        Procession *procession;
        std::vector<std::vector<Person *>> grid;

    public:
        Demonstration(int wid, int len, Procession *proc);
        ~Demonstration();

        // SDA : Simulation d'une étape
        void simStage();

        // SDA : Test de fin
        bool hasEnded() const;

        // SDA : Accès à une personne à partir de son identifiant
        Person getPerson(int id);

        // SDA : Suppression d'une personne à partir de son identifiant
        void removePerson(int id);

        // SDA : Accès à l'ensemble des leaders en train de défiler
        std::vector<Person *> getLeaders() const;

        void displayGrid();

};

#endif
