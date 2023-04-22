#include "person.hpp"
#include <iostream>

using namespace std;

Person::Person(const string & name, int id) : name(name), id(id), position({-1,-1}) {}

Person::~Person() {}

string Person::getName() const{
    return name;
}

int Person::getID() const{
    return id;
}

pair<int, int> Person::getPosition() const{
    return position;
}

void Person::setPosition(const pair<int, int> & newPosition){
    position = newPosition;
}
