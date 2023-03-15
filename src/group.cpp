#include "group.hpp"

#include <iostream>
using namespace std;

struct Member {
    Person member;
    Member *next;
};

Group::Group(string name, string color) {
    this->name = name;
    this->color = color;
    this->leader = nullptr;
    this->last = nullptr;
    //people queue ?
    //group map ?
}


int Group::getSize() const {
  return this->peopleQ.size();
}

string Group::getName() const {
  return this->name; 
}

string Group::getColor() const {
  return this->color;
}
//TODO
Person *Group::getPerson(int id) const {
    
}
//TODO: Iterator stuff...
Person *Group::getLeader() const {
    if(this->getSize() != 0) {
        
    }
}


//unordered_map<int, Person*> Group::createGroup() {}
//TODOS
void Group::insertPerson(Person *Person) {}
void Group::removePerson(int id) {}
void Group::removeLeader() {}

//TODO: iterator impl

Group::~Group() {

}