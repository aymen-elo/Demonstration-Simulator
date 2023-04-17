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

string Procession::getName() const{
    return this->name;
}

Person Procession::getPerson(int id) const{

    for(Group* g : groups) {
        Person p = g->getPerson(id);

        if(p.getID() != -1){
            return p;
        }
    }
    return Person("INEXISTANT", -1);
}

list<Group*> Procession::getGroups() const{
    return this->groups;
}

void Procession::removePerson(int id){

    for(Group* g : groups) {
        Person p = g->getPerson(id);

        if(p.getID() != -1){
            g->removePerson(id);
            cout<<"Person removed"<<endl;
            return;
        }
    }
}
void Procession::sortColor(){}
void Procession::sortSize(){}
Procession::~Procession() {
    for (auto it = groups.begin(); it != groups.end(); ++it) {
        delete *it;
    }
}