#ifndef MANIF_HPP
#define MANIF_HPP
#include <vector>
#include "cortege.hpp"

////////////////////////////////////////////////////
/// since we need to simulate a step where people move forward on the grid,
/// a vector may be a better choice since we need to access elements by their position on the grid.
////////////////////////////////////////////////////

class Manif
{
private:
    int largeur;
    int longueur;
    std::vector<Cortege *> corteges;

public:
    // Constructor: creation the manif
    Manif(int larg, int longe) : largeur(larg), longueur(longe) {}
    // Deconstructor
    ~Manif();

    /// @brief  simulation of a stage ///
    void simulerEtape();

    /// @brief addition Cortege in Manif
    /// @param cortege
    void ajouterCortege(Cortege *cortege);

    /// @brief  deletion Cortege in Manif
    /// @param nom
    void supprimerCortege(const std::string &nom);
    /// @brief test if Manif is finished //
    /// @return false if the case is not finish yet.
    bool estTerminee() const;

    /// @brief access to a person from its identifier
    /// @param id
    /// @return the person
    Personne *trouverPersonne(int id);

    /// @brief deletion of a person from its identifier
    /// @param id
    void supprimerPersonne(int id);

    /// @brief access to all the leaders in the process of scrolling.
    /// @return  an array of leaders
    std::vector<Personne *> getLeaders() const;
};

#endif
