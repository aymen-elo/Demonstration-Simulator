#include "personne.hpp"

using namespace std;

struct Position {
    int x;
    int y;
};

Personne::Personne(std::string n, int id, Position pos)
    : nom(n), id(id), position(pos)
{}

std::string Personne::getNom() const
{
    return nom;
}

int Personne::getId() const{
    return id; 
}
 Position Personne::getPosition() const{
    return position;
 }
 Personne::~Personne(){
    
 }; 

