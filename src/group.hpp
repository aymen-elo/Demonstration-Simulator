#ifndef GROUP_HPP
#define GROUP_HPP

#include "person.hpp"

#include <string>
#include <unordered_map>
#include <list>
/////////////////////////////////////////////////////////////////////////////////
// We are interested in the access to a person from the identifier in the group//
// The time complexity must be a Θ(1). So I use Hashtable here                 //


class Group {
    private:
        int size;
        std::string name;
        std::string color;
        Person* leader;
        Person* last;
        std::list<Person> people;
        std::unordered_map<int, Person*> group;

    public:
        Group(std::string name, std::string color);
        ~Group();

        int getSize() const; 
        std::string getName() const; 
        std::string getColor() const; 
        Person* getPerson(int id) const;
        Person* getLeader() const;

        std::unordered_map<int, Person*> createGroup();

        void insertPerson(Person* person);
        void removePerson(int id);
        void removeLeader();


        class Iterator {
            private:
                Person* current;

            public:
                Iterator(Person* person);
                Person* operator*() const;
                Iterator& operator++();
                bool operator==(const Iterator& other) const;
                bool operator!=(const Iterator& other) const;
        };

        Iterator begin() const;
        Iterator end() const;
}; 


/* class Group {
public:
    Group();
    ~Group();
    int taille() const;
    std::shared_ptr<Person> acces_person(const std::string& id) const;
    void insertion_person(const std::string& id);
    void suppression_person(const std::string& id);
    void suppression_premiere_person();
    std::shared_ptr<Person> acces_leader() const;
private:
    std::shared_ptr<Person> leader_;
    std::unordered_map<std::string, std::shared_ptr<Person>> persons_;
}; */

#endif // Group_HPP