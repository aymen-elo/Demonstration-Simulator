/*Procession <=> Cortege*/

#ifndef PROCESSION_HPP
#define PROCESSION_HPP

#include <vector>
#include <list>
#include "group.hpp"

/*
Procession = Cortège, son nom est le sujet de la manifestation
Les opérations de Procession sont de complexité constante Θ(1)
*/

class Procession {
    private:
        std::string name;
        std::list<Group*> groups;

    public:
        Procession(const std::string & name);
        ~Procession();

        Person *getPerson(int id);

        void addGroup(Group *group);
        void removeGroup(const std::string &name);
        void removePerson(int id);

        void sortColor();
        void sortSize();

        class ProcessIterator {
            private:
                std::list<Group*>::iterator group_it;

            public:
                ProcessIterator(std::list<Group*>::iterator it) : group_it(it) {}

                
                //Opérateur de comparaison pour tester l'égalité de deux itérateurs
                bool operator==(const ProcessIterator& other) const {
                    return group_it == other.group_it;
                }

                bool operator!=(const ProcessIterator& other) const {
                    return group_it != other.group_it;
                }

                ProcessIterator operator++() {
                    ++group_it;
                    return *this;
                }

                Group& operator*() const {
                    return *(*group_it);
                }
        };
        // Méthode begin() pour obtenir un itérateur pointant sur le premier groupe du cortège
        ProcessIterator begin() {
            return ProcessIterator(groups.begin());
        }
        // Méthode end() pour obtenir un itérateur pointant après le dernier groupe du cortège
        ProcessIterator end() {
            return ProcessIterator(groups.end());
        }
}; 
#endif