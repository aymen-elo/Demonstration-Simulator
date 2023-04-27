#include "procession.hpp"

#include <iostream>
using namespace std;

/*
* Procession <=> Cortège s'agit de plusieurs Groups, regroupés autour d'un meme sujet
*/

/* 
** @param name le sujet qui rassemble les groupes
** @return un nouvel objet Procession c.f
*/
Procession::Procession(const string &name){
    this->name = name;
    this->size = 0;
}

/* La taille du cortège correspond au nombre total de personnes
** @return taille du cortège
*/
int Procession::getSize() const {
    return this->size;
}


/* Retourner le sujet qui rassemble les groupes
** @return le nom du cortège
*/
string Procession::getName() const{
    return this->name;
}

/* Accèder à tout les groupes du cortège
** @return liste chainée de pointeurs vers Groups
*/
list<Group*> Procession::getGroups() const{
    return this->groups;
}

/* Rechercher la personne dans tous les groupes du cortège;
** L'exception est levée pour chaque groupe dans lequel la personne
** n'est pas présente. On vérifie alors qu'on a parcouru tous les
** groupes du cortège avant de lancer une exception 'finale'
** @param id identifiant d'une Personne
** @return reference à la Personne recherchée
*/
Person& Procession::getPerson(int id) const{

    //Sert de compteur pour savoir si tout les groupe du cortege on été
    //parcouru dans la liste groups
    uint64_t count = 0;

    //Parcours des groupes du cortège
    for(Group *g : groups) {
        count++;

        try{
            return g->getPerson(id);//recherche de la personne dans le groupe actuel

        //L'exception est levée quand on ne trouve 
        //pas la personne dans le groupe actuel
        }catch(invalid_argument e) {

            //Si on a parcouru tout les groupes du cortège
            if(count >= groups.size()) {
                break;
            }
        }
    }

    //Ligne atteinte seulement si la personne n'est pas trouvée dans tous les groupes
    throw invalid_argument("Personne non présente dans le cortège");
}

/* Accèder à un groupe du cortège à partir de son nom
** @param nom du groupe
** @return copie du groupe
*/
Group Procession::getGroup(string name) const {

    if(groups.size() == 0){
        throw logic_error("Cortège vide");
    }

    for(Group *g : groups) {
        if(g->getName() == name) {
            return *g;
        }
    }

    //On atteint cette ligne uniquement quand le groupe n'est pas trouvé
    throw invalid_argument("Groupe non présent dans le cortège");
}

/* Ajouter un groupe au cortège
** @param group pointeur vers un objet groupe
*/
void Procession::addGroup(Group *group){
    groups.push_back(group);
    size++;
}


/* Retirer et détruire un groupe du cortège
** @param name nom du groupe à retirer
*/
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
            size--;
            return;
        }
    }

    //Ligne atteinte dans le cas ou le nom du groupe a retirer
    //ne correspond pas à un groupe présent dans le cortège
    throw logic_error("Groupe non présent dans le cortège");
}

/* Retirer et détruire une personne du cortège
** @param id l'identifiant de la personne
*/
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

/* Trier les groupes du cortège par ordre alphabétique des couleurs
*/
void Procession::sortColor(){
    quickSortColor(groups.begin(), groups.end()); 
}

/* Tri rapide implémenté pour la SDC du cortège utilisée
** @param begin iterateur vers le début
** @param end itérateur vers la fin
*/
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

/* Détruire un objet cortège
*/
Procession::~Procession() {
    for (auto it = groups.begin(); it != groups.end(); ++it) {
        delete *it;
    }
}