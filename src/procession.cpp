#include "procession.hpp"

#include <iostream>
using namespace std;

/*
* Procession <=> Cortège s'agit de plusieurs Groups, regroupés autour d'un meme sujet
*/

Procession::Procession(const string &name){
    this->name = name; 
}

string Procession::getName() const{
    return this->name;
}

list<Group*> Procession::getGroups() const{
    return this->groups;
}


//La fonction recherche la personne dans tout les groupes du cortège
//L'exception est levée pour chaque groupe dans lequel la personne
//n'est pas présente. Mais On vérifie qu'on a bien parcouru tout les
//groupes du cortège avant de lancer une exception 'finale'
Person Procession::getPerson(int id) const{
    uint64_t count = 0;

    //Parcours des groupes du cortège
    for(Group *g : groups) {
        count++;

        try{
            Person p = g->getPerson(id);//recherche de la personne dans le groupe actuel
            return p;
        //L'exception est levée quand on ne trouve 
        //pas la personne dans le groupe actuel
        }catch(invalid_argument e) {

            //Si on a parcouru tout les groupes du cortège
            if(count >= groups.size()) {
                throw invalid_argument("Personne non présente dans le cortège");
            }
        }
    }
}


void Procession::addGroup(Group *group){
    groups.push_back(group);
}



void Procession::removeGroup(const string &name) {
    
    if(groups.size() == 0){
        throw logic_error("Cortège vide");
    }

    //Recherche du groupe dans le cortege par nom
    for (auto it = groups.begin(); it != groups.end(); ++it) {
        
        if ((*it)->getName() == name) {

            //Destruction puis retrait du groupe
            delete *it;
            groups.erase(it);
            return;
        }
    }

    throw logic_error("Groupe non présent dans le cortège");
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
void Procession::sortColor(){
    quickSortColor(groups.begin(), groups.end()); 
}
void Procession::quickSortColor(list<Group*>::iterator begin, list<Group*>::iterator end){
    
    if (distance(begin,end) < 2){
      return;
    }
    else{
          list<Group*>::iterator pivot = next(begin, distance(begin,end)/2);
          list<Group*>::iterator middle = partition(begin, end, [pivot](const Group* group){
            return (group->getColor() < (*pivot)->getColor());
          });
          // Recusrive de trier le groupe par couleur//
          quickSortColor(begin, middle); 
          quickSortColor(middle,end); 
    }
}

///////////////////////////////////////Mis en commentaire pour compilation
// void Procession::sortSize(){
//     for ( auto it1 = groups.begin(); it1 != groups.end(); it1++){
//         for (auto it2 = it1; it2 != groups.begin(); it2--){
//             if( (*it2)->getSize() > (*(prev(it2))->getSize()){
//                 std::swap(*it2, *(std::prev(it2)));
//             })
//         }
//     }
// }
Procession::~Procession() {
    for (auto it = groups.begin(); it != groups.end(); ++it) {
        delete *it;
    }
}