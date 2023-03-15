/*Procession <=> Cortege*/

#ifndef PROCESSION_HPP
#define PROCESSION_HPP

#include <vector>
#include <list>
#include "group.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// because We are also interested in the identification and extraction of a person knowing the identifier//
/// in case of emergency,                                                                                 //
/// This is the operations involve inserting or deleting elements in the middle of the structure.         //
/// So I dicided using LINKED LIST                                                                        //
////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Procession {
    private:
        std::string name;
        std::vector<Group *> groups;

    public:
        Procession(const std::string &name);
        ~Procession();

        /// @brief insertion of a Group into Procession
        /// @param group
        void ajouterGroupe(Group *group);

        //// @brief deletion of a Group ////
        //// @param name of the Group ////
        void deleteGroup(const std::string &name);

        /// @brief acces a person in Procession ////
        /// @param id identifier of the Person ///
        /// @return return person
        Person *getPerson(int id);

        /// @brief deletion person in Procession ////
        /// @param id identifier of the Person
        void removePerson(int id);

        /// @brief sorting by color of the groups ///
        void sortColor();

        /// @brief sorting by Size of the groups ///
        void sortSize();

        // Iterators
        typedef std::vector<Group *>::iterator iterator;
        iterator begin() { return groups.begin(); }
        iterator end() { return groups.end(); }
};

#endif
