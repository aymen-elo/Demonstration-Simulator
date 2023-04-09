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

        class iterator {
            private:
                std::list<Group*>::iterator group_it;

            public:
                iterator(std::list<Group*>::iterator it) : group_it(it) {}

                
                //Opérateur de comparaison pour tester l'égalité de deux itérateurs
                bool operator==(const iterator& other) const {
                    return group_it == other.group_it;
                }

                bool operator!=(const iterator& other) const {
                    return group_it != other.group_it;
                }

                iterator operator++() {
                    ++group_it;
                    return *this;
                }

                Group& operator*() const {
                    return *(*group_it);
                }
        };
        // Méthode begin() pour obtenir un itérateur pointant sur le premier groupe du cortège
        iterator begin() {
            return iterator(groups.begin());
        }
        // Méthode end() pour obtenir un itérateur pointant après le dernier groupe du cortège
        iterator end() {
            return iterator(groups.end());
        }
}; 
#endif