#include "demonstration.hpp"


using namespace std;


//On suppose que le cortège est déjà construit
Demonstration::Demonstration(int wid, int len, Procession *proc) : width(wid), length(len), procession(proc) {
    // Initialiser la grille avec des pointeurs nuls
    grid = vector<vector<Person*>>(wid, vector<Person*>(len, nullptr));

    //Calcul du nombre de personnes au total
    int numPeople = 0;
    for(Group *g : procession->getGroups()) {
        numPeople += g->getSize();
    }

    //Parcours de toutes les personnes a l'aide des ID (croissant 0, 1, 2...)
    for(int i = 0; i < numPeople/2; i++) {

        Person *p = &procession->getPerson(i);

        //Calcul et affectation de la position sur y grace à l'ID et la largeur de la grille
        pair<int,int> initialPosition = {p->getPosition().first, p->getID()%width};       
        p->setPosition(initialPosition); 
    }
}

Demonstration::~Demonstration() {
    // Libérer la mémoire allouée pour les processions
    delete procession;
}

void Demonstration::updatePosition(int id) {

    //Une reference vers notre personne 
    Person p = procession->getPerson(id);

    //Actualisation du membre position
    pair<int,int> updatedPosition = {p.getPosition().first+1, p.getPosition().second};
    p.setPosition(updatedPosition);

}

void Demonstration::simStage() {
    //a mimir
    Sleep(1000);

    //Parcours des personnes concernées par le changement de position
    for(int i = 0; i < width*stageCount; i++) {
        updatePosition(i);
    }

    //Pour chaque ligne de la fin de la grille jusqu'a un seuil
    //le seuil correspond a la rangée ou les manifestants ont le
    //le plus avancé
    for(int i = length - 1; i >= length - stageCount; i--) {

        for(int j = 0; j < width; j++) {
            
            try {
                grid[i][j] = &procession->getPerson(i);
            }catch(invalid_argument e) {
                grid[i][j] = nullptr;
            }
        }
    }


    displayGrid();

    stageCount++;
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

    return procession->getPerson(id);
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
    
    for(int i = length-1; i >= 0; i--) {
        cout<<i+1<<" ";

        for(int j = 0; j < width; j++) {

            Person *p = grid[i][j];

            if(p == nullptr) {
                cout<<"_ ";
            }else{
                string color;
                int id = p->getID();

                //Parcours des groupes pour retrouver la couleur
                for(Group *g : procession->getGroups()) {
                    
                    try{
                        g->getPerson(id);

                        //Au succès l'exception n'est pas levée et on casse la boucle
                        //On retrouve donc la couleur a utiliser pour l'affichage
                        color = g->getColor();
                        break;

                    //Exception levée si la personne n'est pas dans le groupe actuel
                    }catch(invalid_argument e) {
                        continue;
                    }
                }
                
                Couleur col = Couleur::creer(color);

                col.afficher(cout, p->getName().substr(0,1));
                cout<<" ";
            }

        }
        cout<<endl;
    }

    cout<<"  ";
    for(int j = 0; j < width; j++) {
        cout<<j+1<<" ";
    }
    cout<<endl;
}


