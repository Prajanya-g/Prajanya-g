#ifndef PLAYER_H
#define PLAYER_H
#include "Bag.h"
#include "Character.h"
#include "Item.h"
#include <string>
#include <iostream>

// defining the child class Player inherting from character
class Player :public Character{
protected:
    Bag* myBag; // assigning a bag to the player
    
public:
    Player(std::string name, bool aliveStatus, Bag* myBag); // Constructor taking a string for name and a bool value for alive or not
    void setName(std::string name); // set function for name
    void say(); // output the sentence
    void setBag(Bag* myBag); // set function for bag
    Bag* getBag(); // get function for bag
    ~Player(); //destructure
};
#endif
