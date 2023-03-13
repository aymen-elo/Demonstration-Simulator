#ifndef CORTEGE_HPP
#define CORTEGE_HPP

#include "groupe.hpp"

#include <list>
#include "groupe.hpp"

//////////////////////////////////////////////////////////
/// because We are also interested in the identification and extraction of a person knowing the identifier
/// in case of emergency,
/// This is the operations involve inserting or deleting elements in the middle of the structure.
/// So I dicided using LINKED LIST
/////////////////////////////////////////////////////////
class Cortege
{
private:
    std::string nom;
    std::vector<Groupe *> groupes;



    
public:
    //// Constructor fof the Cortege to creation a Cortege empty ////
    Cortege(const std::string &nom) : nom(nom) {}
    //// Deconstructor ////
    ~Cortege() {}

    /// @brief insertion of a Group into  Cortege
    /// @param groupe
    void ajouterGroupe(Groupe *groupe);

    /// @brief deleting of a Group ////
    //// @param name of the Group passed in the parameter ////
    void supprimerGroupe(const std::string &nom);

    /// @brief acces to a person in Cortege ////
    /// @param id identifier of the person ///
    /// @return return person
    Personne *trouverPersonne(int id);

    /// @brief deletion person in Cortege ////
    /// @param id identifier of the person
    void supprimerPersonne(int id);

    /// @brief sorting by color of the group ///
    void trierParCouleurs();

    /// @brief sorting by Size of the group ///
    void trierParTailles();

    // Itérateurs
    typedef std::vector<Groupe *>::iterator iterator;
    iterator begin() { return groupes.begin(); }
    iterator end() { return groupes.end(); }


};

#endif
