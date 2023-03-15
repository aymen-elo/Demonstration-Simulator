#include <iostream>
#include <string>
#ifndef PERSON_HPP
#define PERSON_HPP

struct Position {
    int x;
    int y;
};

class Person {
    private:
        int id;
        std::string name;
        Position position;

    public:
        Person(int id, std::string name, Position pos);
        ~Person();

        int getId() const;
        std::string getName() const;
        Position getPosition() const;
};


#endif