#include "person.hpp"
#include <iostream>

using namespace std;

//Partie permettant de construire une perssone avec un attribution d'id automatique
int Person::nextID = 0;
Person::Person(const string & name) : name(name), id(nextID), position({-1,-1}) {nextID++;}

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
