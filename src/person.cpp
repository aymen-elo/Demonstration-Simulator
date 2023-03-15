#include "person.hpp"

using namespace std;



Person::Person(int id, string name, Position pos){
    this->id = id;
    this->name = name;
    this->position = pos;
}

string Person::getName() const {
    return this->name;
}

int Person::getId() const {
    return this->id; 
}

Position Person::getPosition() const {
    return this->position;
}

Person::~Person() {
}