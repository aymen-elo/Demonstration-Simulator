#include "groupe.hpp"
#include <iostream>

#include "groupe.hpp"

struct Member {
  Personne mem;
  Member *next;
};

// Constructor
Groupe::Groupe(std::string n, std::string cl) {
  this->nom = n;
  this->couleur = cl;
  this->taille = 0;
  this->leader = nullptr;
  this->dernier = nullptr;
  creerGroupe();
}

// Getters
int Groupe::getSize() const { return this->taille; }

std::string Groupe::getNomGroupe() const { return this->nom; }

std::string Groupe::getColor() const { return this->couleur; }

std::unordered_map<int, Personne *> creerGroupe() {}

void Groupe::insererPersonne(Personne *personne) {}
void Groupe::supprimerPersonne(int id) {}
void Groupe::supprimerLeader() {}
Personne *Groupe::getPersonne(int id) const {}
Personne *Groupe::getLeader() const {}