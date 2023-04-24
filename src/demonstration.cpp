#include "demonstration.hpp"

Demonstration::Demonstration(int wid, int len) : width(wid), length(len) {
    // Initialiser la grille avec des pointeurs nuls
    grid = std::vector<std::vector<Person*>>(wid, std::vector<Person*>(len, nullptr));
}

Demonstration::~Demonstration() {
    // Libérer la mémoire allouée pour les processions
    for (auto proc : processions) {
        delete proc;
    }
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
    // On parcourt chaque personne de chaque groupe de chaque procession
    for (Procession* procession : processions) {
        for (Group* group : procession->getGroups()) {
            // On utilise la méthode getPerson de la classe Group pour récupérer la personne correspondant à l'ID
            Person person = group->getPerson(id);
            // Si l'ID de la personne correspond à celui cherché, on la retourne
            if (person.getID() == id) {
                return person;
            }
        }
    }
    // Si on n'a pas trouvé la personne, on lève une exception
    throw std::invalid_argument("Personne non trouvée");
}



void Demonstration::removePerson(int id) {
    // On parcourt chaque procession de la manifestation
    for (Procession* procession : processions) {
        // On appelle la méthode removePerson de la procession courante
        procession->removePerson(id);
    }
}



std::vector<Person*> Demonstration::getLeaders() const {
    std::vector<Person*> leaders;
    // On parcourt chaque groupe de chaque procession
    for (Procession* procession : processions) {
        for (Group* group : procession->getGroups()) {
            // On ajoute le leader de chaque groupe à la liste des leaders si le groupe n'est pas vide
          
        }
    
    return leaders;
}
}




