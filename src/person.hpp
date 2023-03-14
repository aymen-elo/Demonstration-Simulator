#include <iostream>
#include <string>
#ifndef PERSON_HPP
#define PERSON_HPP


class Person {
    private:
        int id;
        std::string name;
        Position position;

    public:
        Person(int id, std::string name, Position position);
        ~Person();

        int getId() const;
        std::string getName() const;
        Position getPosition() const;
};


#endif