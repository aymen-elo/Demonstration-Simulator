#include "person.hpp"

using namespace std;



struct Position {
    int x;
    int y;
};

Person::Person(int id, std::string name, Position pos){

}

std::string Person::getName() const {
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