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
        std::vector<std::vector<Person *>> grid;
        int numPeople;

        int stageCount = 1;
        int stageCountMax;
        bool sig = false;
        bool lastRowFlag = false;

    public:
        Demonstration(int wid, int len, Procession *proc);
        ~Demonstration();

        void simStage();
        bool hasEnded() const;


        Person getPerson(int id);

        void removePerson(int id);

        std::vector<Person *> getLeaders() const;

        void displayGrid();

        void updatePosition(int id);

};

#endif
