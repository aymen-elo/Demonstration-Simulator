#ifndef DEMONSTRATION_HPP
#define DEMONSTRATION_HPP
#include <vector>
#include "procession.hpp"

/*
Demonstration = Manif est un Procession (Cortege) qui se déplace
*/

class Demonstration {
    private:
        int width;
        int length;
        std::vector<Procession *> processions;

    public:
        Demonstration(int wid, int len);
        ~Demonstration();

        void simStage();
        bool hasEnded() const;
        Person *getPerson(int id);
        void removePerson(int id);
        std::vector<Person *> getLeaders() const;

        ///TODO: discuss insert & remove///
        //void insertProcession(Procession *procession);
        //void removeProcession(const std::string &name);
};

#endif
