#ifndef GROUPE_HPP
#define GROUPE_HPP

#include<string>
#include <unordered_map>
//////////////////////////
// We are interested in the access to a person from the identifier in the group
// The time complexity must be a Θ(1). So I use Hashtable here // 
#include "personne.hpp"

class Groupe {
private:
    std::string nom;
    std::string couleur;
    int taille;
    Personne* leader;
    Personne* dernier;
    std::list<Personne> personnes;
    std::unordered_map<int, Personne*> groupe;

public:
    Groupe(std::string nom, std::string couleur);
    ~Groupe();
    //Getters
    int getSize() const; 
    std::string getNomGroupe() const; 
    std::string getColor() const; 

  //////////////////////OPERATIONS///////////////
  
    std::unordered_map<int, Personne*> creerGroupe(); 
    // Insert a person with the given name //
    void insererPersonne(Personne* personne);
    // Remove the person with the given id //
    void supprimerPersonne(int id);
    //Remove leader of the group //
    void supprimerLeader();

    //Returns the person with the given identifier //
    Personne* getPersonne(int id) const;
    //Returns the leader of the group //
    Personne* getLeader() const;

    class Iterator {
    private:
        Personne* current;


    public:
        Iterator(Personne* personne);
        Personne* operator*() const;
        Iterator& operator++();
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;

  
  
    };

    Iterator begin() const;
    Iterator end() const;


}; 


/* class Groupe {
public:
    Groupe();
    ~Groupe();
    int taille() const;
    std::shared_ptr<Personne> acces_personne(const std::string& id) const;
    void insertion_personne(const std::string& id);
    void suppression_personne(const std::string& id);
    void suppression_premiere_personne();
    std::shared_ptr<Personne> acces_leader() const;
private:
    std::shared_ptr<Personne> leader_;
    std::unordered_map<std::string, std::shared_ptr<Personne>> personnes_;
}; */

#endif // GROUPE_HPP