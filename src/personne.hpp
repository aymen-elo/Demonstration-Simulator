#include <iostream>
#include <string>
#ifndef PERSONNE_HPP
#define PERSONNE_HPP


struct Position {
    int x;
    int y;
};


class Personne {
    private:
        std::string nom;
        int id;
        Position position;

    public:
        Personne(std::string nom, int id, Position position);
        ~Personne();

        std::string getNom() const;
        int getId() const;
        Position getPosition() const;
};


#endif