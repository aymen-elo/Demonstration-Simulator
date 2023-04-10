#include "procession.hpp"

#include <iostream>
using namespace std;

Procession::Procession(const std::string &name){
    this->name = name; 
}


void Procession::addGroup(Group *group){

    if (groups.empty() || group->getName() < groups.front()->getName()) {
        groups.push_front(group); 
    }else{
        std::list<Group*>::iterator it;
        for (it = groups.begin(); it != groups.end(); it++) {
            if ((*it)->getName() > group->getName()) {
                groups.insert(it, group);
                break;
            }
        }
        if (it == groups.end()) {
            groups.push_back(group);
        }
    }
}


void Procession::removeGroup(const std::string &name){
    for (const auto &rm : groups){
        if (rm->getName() == name){
            
        }
    }
}
Person Procession::getPerson(int id) const{

    for(Group* g : groups) {
        
        auto it = g->getGroupMap().find(id);
        if(it != g->getGroupMap().end()) {
            return it->second->p;
        }
    }
}

void Procession::removePerson(int id){}
void Procession::sortColor(){}
void Procession::sortSize(){}
Procession::~Procession() {
    for (auto it = groups.begin(); it != groups.end(); ++it) {
        delete *it;
    }
}