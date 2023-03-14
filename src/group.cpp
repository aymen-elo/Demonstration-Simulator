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
  this->size = 0;
  this->leader = nullptr;
  this->last = nullptr;
}


int Group::getSize() const { return this->size; }
string Group::getName() const { return this->name; }
string Group::getColor() const { return this->color; }
Person *Group::getPerson(int id) const {}
Person *Group::getLeader() const {}


unordered_map<int, Person*> Group::createGroup() {}
void Group::insertPerson(Person *Person) {}
void Group::removePerson(int id) {}
void Group::removeLeader() {}

//TODO: iterator impl

Group::~Group() {

}