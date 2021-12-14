#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <iostream>
#include "Action.h"

// defining the character class
class Character: public Action{
protected:
    std::string name; // name of the character
    bool aliveStatus; // true if the character is alive else false
    
public:
    Character();
    Character(std::string name, bool aliveStatus); // Constructor taking a string for name and a bool value for alive or not
    virtual void say(); // virtual function
    void changeStatus(bool status); // changes the aliveStatus
    std::string getStatus(); // returns the aliveStatus
    std::string getName(); // returns name of the character
    ~Character(); //destructure
};
#endif
