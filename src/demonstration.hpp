#ifndef DEMONSTRATION_HPP
#define DEMONSTRATION_HPP
#include <vector>
#include "procession.hpp"

////////////////////////////////////////////////////
/// since we need to simulate a step where people move forward on the grid,
/// a vector may be a better choice since we need to access elements by their position on the grid.
////////////////////////////////////////////////////

class Demonstration {
    private:
        int width;
        int length;
        std::vector<Procession *> processions;

    public:
        Demonstration(int wid, int len);
        ~Demonstration();

        /// @brief  simulation of a stage ///
        void simStage();

        /// @brief test if Demo is finished //
        /// @return false when not finished yet.
        bool hasEnded() const;

        /// @brief access to a Person using its identifier
        /// @param id
        /// @return the person
        Person *getPerson(int id);

        /// @brief deletion of a Person using its identifier
        /// @param id
        void removePerson(int id);

        /// @brief access to all the leaders in the process of scrolling.
        /// @return  an array of leaders
        std::vector<Person *> getLeaders() const;

        ///TODO: discuss insert & remove///
        /// @brief addition of Procession in Demonstration
        /// @param Procession
        //void insertProcession(Procession *procession);
        /// @brief deletion of Procession in Demonstration
        /// @param name
        //void removeProcession(const std::string &name);
};

#endif
