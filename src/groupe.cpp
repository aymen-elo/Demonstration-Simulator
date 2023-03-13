#include "groupe.hpp"
#include <iostream>

#include "groupe.hpp"

struct Member {
  Personne mem;
  Member *next;
};

Groupe::Groupe(std::string name, std::string color) {
  this->nom = name;
  this->couleur = color;
  this->taille = 0;
  this->leader = nullptr;
  this->dernier = nullptr;
  creerGroupe();
}


int Groupe::getSize() const { return this->taille; }

std::string Groupe::getNom() const { return this->nom; }

std::string Groupe::getColor() const { return this->couleur; }

std::unordered_map<int, Personne *> creerGroupe() {}

void Groupe::insererPersonne(Personne *personne) {}
void Groupe::supprimerPersonne(int id) {}
void Groupe::supprimerLeader() {}
Personne *Groupe::getPersonne(int id) const {}
Personne *Groupe::getLeader() const {}