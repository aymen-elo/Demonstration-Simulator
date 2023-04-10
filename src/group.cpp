#include "group.hpp"

#include <iostream>
using namespace std;

Group::Group(string name, string color, int size){
    this->name = name;
    this->color = color;
    this->size = size;
    this->leader = nullptr;
    this->last = nullptr;
}

int Group::getSize() const{
    return this->size;
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
    }else{
        return Person("INEXISTANT", -1);
    }
}

Person Group::getLeader() const{
    auto it = groupMap.begin();
    cout << "Leader of group is " << endl;
    return it->second->p;
}

std::unordered_map<int, Node* > Group::getGroupMap(){
    return this->groupMap;
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
    size++;
}

void Group::removePerson(int id){

    auto it = groupMap.find(id);

    // id trouvé dans la map
    if (it != groupMap.end()){
        Node *nodeToRemove = it->second;

        if (nodeToRemove == leader){
            leader = leader->next;
            leader->prev = nullptr;
        }

        if (nodeToRemove == last){
            last = last->prev;
            last->next = nullptr;
        }

        if (nodeToRemove->prev != nullptr){
            nodeToRemove->prev->next = nodeToRemove->next;
        }

        if (nodeToRemove->next != nullptr){
            nodeToRemove->next->prev = nodeToRemove->prev;
        }

        delete nodeToRemove;
        groupMap.erase(it);
        size--;
    }else{
        cout << "Person with id " << id << " not found" << endl;
    }
}

void Group::removeLeader(){

    if (groupMap.empty()){
        cout << " This group is empty " << endl;
        return;
    }

    Node *oldLeader = leader;
    leader = leader->next;

    if (leader != nullptr){
        leader->prev = nullptr;
    }else{
        last = nullptr;
    }

    delete oldLeader;
    cout << "Leader removed from the group" << endl;

    groupMap.erase(groupMap.begin());
    size--;
}

// TODO: iterator impl

Group::~Group(){}
