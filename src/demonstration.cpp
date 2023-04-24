#include "demonstration.hpp"


using namespace std;

//On suppose que le cortège est déjà construit
Demonstration::Demonstration(int wid, int len, Procession *proc) : width(wid), length(len), procession(proc) {
    // Initialiser la grille avec des pointeurs nuls
    grid = vector<vector<Person*>>(wid, vector<Person*>(len, nullptr));
}

Demonstration::~Demonstration() {
    // Libérer la mémoire allouée pour les processions
    delete procession;
}

void Demonstration::simStage() {

}



bool Demonstration::hasEnded() const {
    // On parcourt chaque case de la dernière ligne de la grille
    for (int i = 0; i < width; i++) {
        if (grid[i][length - 1] != nullptr) {
            return false; // Si une personne est encore présente, la manifestation n'a pas encore fini
        }
    }
    return true; // Sinon, la manifestation est terminée
}


Person Demonstration::getPerson(int id) {

    for (Group* group : procession->getGroups()) {
        // On utilise la méthode getPerson de la classe Group pour récupérer la personne correspondant à l'ID
        Person person = group->getPerson(id);
        // Si l'ID de la personne correspond à celui cherché, on la retourne
        if (person.getID() == id) {
            return person;
        }
    }

    // Si on n'a pas trouvé la personne, on lève une exception
    throw invalid_argument("Personne non trouvée");
}



void Demonstration::removePerson(int id) {
    // On parcourt chaque procession de la manifestation
    procession->removePerson(id);
}



vector<Person*> Demonstration::getLeaders() const {
    vector<Person*> leaders;

    // On parcourt chaque groupe
    for (Group* group : procession->getGroups()) {
        // On ajoute le leader de chaque groupe à la liste des leaders si le groupe n'est pas vide
        
    }

    return leaders;
}


void Demonstration::displayGrid() {
    
    for(int j = length; j > 0; j--) {
        cout<<j<<" ";

        for(int i = 0; i < width; i++) {
        
            cout<<"_ ";
            
            //TODO : le cas ou on a une personne à cette position

        }
        cout<<endl;
    }

    cout<<"  ";
    for(int i = 0; i < width; i++) {
        cout<<i+1<<" ";
    }
}


