#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <set>
#include <time.h>
#include "demonstration.hpp"
#include "couleur.hpp"


using namespace std;

void displayGroupMembers(Group *g) {
    
    if(g->getSize() == 0) {
        cout<<endl<<g->getName()<<" est vide"<<endl;
        return;
    }

    cout<<endl;
    auto it = g->getGroupMap().find(g->getLeader().getID());
    Node *temp = it->second;

    cout<<endl<<"Groupe : "<<g->getName()<<endl;

    while(temp != nullptr) {
        cout<<temp->p->getName()<<" - ";
        temp = temp->next;
    }
    cout<<endl;
}

////////////////////////////////////////////////////////////////////////////////
// choix aléatoire d'un élément dans l'ensemble passé en paramètre
std::string choisir_prenom(const set<std::string>& s){
   int n = s.size(),
       k = rand() % n;

   auto it = s.begin();
   std::advance(it, k);
   return *it;
}

////////////////////////////////////////////////////////////////////////////////
// lecture du fichier des prénoms
void lecture_fichier_prenoms(set<std::string>& ens){
   ifstream fin;
   fin.open("nat2021.csv", ios::in);
   string line, mot;

   while (fin >> line){
      istringstream is(line);
      getline(is, mot, ';');
      getline(is, mot, ';');
      ens.insert(mot);
   }
   fin.close();
}

////////////////////////////////////////////////////////////////////////////////
int main(){

    // initialisation du générateur de nombres aléatoires
    srand(time(0));

    // lecture du fichier des prénoms
    set<std::string> ens_prenom;
    lecture_fichier_prenoms(ens_prenom);

    // lecture du fichier des corteges
    ifstream fcor;
    fcor.open("declaration.csv", ios::in);
    std::string line, nom, couleur, str, sujet;
    int taille;
    
    getline(fcor, sujet);

    // TODO : création d'un cortège

    /*Cortege créé*/
    Procession *pr = new Procession(sujet); //Mu zik !

    //Iteration sur les groupes dans declaration.csv
    while (fcor >> line){
        istringstream is(line);
        getline(is, nom, ';');
        getline(is, couleur, ';');
        getline(is, str, ';');
        taille = stoi(str);



        /*Ajout du groupe actuel au cortege*/
        Group *g = new Group(nom, couleur, taille); //it 1 : Group(electro, vert, 8)
        pr->addGroup(g);

        /*Insertion de personne dans le groupe actuel dans le groupe*/
        for(int i = 0; i < taille; i++) {
            Person *p = new Person(choisir_prenom(ens_prenom));
            g->insertPerson(p);
        }
    }
    fcor.close();

    Demonstration *d = new Demonstration(3,3,pr);

    while(true) {
        d->simStage();
    }

    cout<<endl<<"Fin";



    return 0;
}
