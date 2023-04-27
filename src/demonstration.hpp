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

        bool hasEnded() const;
        Person getPerson(int id);
        void removePerson(int id);
        std::vector<Person *> getLeaders() const;

        void updatePosition(int id);
        void simStage();
        void displayGrid();
};

#endif
