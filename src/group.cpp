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
        cout << "Found person " << it->second->p.getName() << endl;
        return it->second->p;
    }
}

Person Group::getLeader() const{
    auto it = groupMap.begin();
    cout << "Leader of group is " << endl;
    return it->second->p;
}

void Group::insertPerson(Person *person){

    // Si la personne est déjà dans le groupe on ne le rajoute pas
    if (groupMap.find(person->getID()) != groupMap.end()){
        cout << "Person with id " << person->getID() << " is already in the group" << endl;
        return;
    }

    // Sinon on crée un nouveau maillon
    Node *newNode = new Node;
    newNode->p = *person;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    // La personne est leader + dernier si la liste est vide
    if (leader == nullptr){
        leader = newNode;
        last = newNode;
    // Sinon, la personne est insérée à la fin de la liste
    }else{
        last->next = newNode;
        newNode->prev = last;
        last = newNode;
    }
    // Insertion de la personne dans la map
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
        cout << "Person with id " << id << " not found" << endl;
    }
}

void Group::removeLeader(){
    for (const auto &rm : groupMap){
        if (!groupMap.empty()){
        cout << " This group is empty " << endl;
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
                cout << "Leader removed from the group" << endl;
            }
            groupMap.erase(groupMap.begin());
        }
    }
}

// TODO: iterator impl

Group::~Group(){}
