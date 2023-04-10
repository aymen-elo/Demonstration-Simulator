#include "group.hpp"

#include <iostream>
using namespace std;

Group::Group(string name, string color){
    this->name = name;
    this->color = color;
    this->leader = nullptr;
    this->last = nullptr;
}

int Group::getSize() const{
    Node *temp = leader;

    //Dans le cas ou la map n'est pas initialisée
    //On retourne taille = 0
    if(temp == nullptr){
        return 0;
    }else{
        return this->groupMap.size();
    }
}

string Group::getName() const{
    return this->name;
}

string Group::getColor() const{
    return this->color;
}

Person Group::getPerson(int id) const{
    auto it = this->groupMap.find(id);
    if (it != groupMap.end()){
        std::cout << "Found person " << it->second->p.getName() << std::endl;
        return it->second->p;
    }
    // si je peux pas trouver la personne, qu'est-ce que je retourne?
}

Person Group::getLeader() const{
    auto it = groupMap.begin();
    std::cout << "Leader of group is " << std::endl;
    return it->second->p;
}

void Group::insertPerson(Person *person){
    // Create a new node for the person
    Node *newNode = new Node;
    newNode->p = *person;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    // Check if the person is already in the group
    if (groupMap.find(person->getID()) != groupMap.end()){
        std::cout << "Person with id " << person->getID() << " already in the group" << std::endl;
        return;
    }else{
        // If the linked list is empty, set the new node as both the leader and the last node
        if (leader == nullptr){
            leader = newNode;
            last = newNode;
        // insert new node to the end of linked list
        }else{
            last->next = newNode;
            newNode->prev = last;
            last = newNode;
        }
    }
    // then, add this person in map
    groupMap.insert({person->getID(), newNode});
}

void Group::removePerson(int id){
    auto it = groupMap.find(id);
    /* if id is found in map, remove it*/
    if (it != groupMap.end()){
        Node *nodeToRemove = it->second;
        if (nodeToRemove == leader){
        leader = leader->next;
        }
        if (nodeToRemove == last){
        last = last->prev;
        }
        if (nodeToRemove->prev != nullptr){
        nodeToRemove->prev->next = nodeToRemove->next;
        }
        if (nodeToRemove->next != nullptr){
        nodeToRemove->next->prev = nodeToRemove->prev;
        }
        delete nodeToRemove;
        groupMap.erase(it);
    }
    else{
        std::cout << "Person with id " << id << " not found" << std::endl;
    }
}

void Group::removeLeader(){
    for (const auto &rm : groupMap){
        if (!groupMap.empty()){
        std::cout << " This group is empty " << std::endl;
        }else{
            if (leader != nullptr){
                Node *oldLeader = leader;
                leader = leader->next;
                if (leader != nullptr){
                leader->prev = nullptr;
                }
                else{
                last = nullptr;
                }
                delete oldLeader;
                std::cout << "Leader removed from the group" << std::endl;
            }
            groupMap.erase(groupMap.begin());
        }
    }
}

// TODO: iterator impl

Group::~Group(){}
