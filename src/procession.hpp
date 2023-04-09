#include "procession.hpp"

#include <iostream>
using namespace std;

Procession::Procession(const std::string &name){
    this->name = name; 
}


void Procession::addGroup(Group *group){
    
    if (groups.empty() ) {
        groups.push_front(group); 
    }
    else {
        auto it = groups.begin();
        while (it != groups.end() && (*it)->getColor() <= group->getColor()) {
            ++it;
        }
    }
}


void Procession::removeGroup(const std::string &name){
    for (const auto &rm : groups){
        if (rm->getName() == name){
            
        }
    }
}
Person Procession::*getPerson(int id){}
void Procession::removePerson(int id){}
void Procession::sortColor(){}
void Procession::sortSize(){}
Procession::~Procession() {
        for (auto it = groups.begin(); it != groups.end(); ++it) {
            delete *it;
        }
    }
   