#ifndef MONSTER_H
#define MONSTER_H
#include "Item.h"
#include "Character.h"
#include <string>
#include <iostream>

// defining teh child class monster inherting from the parent class character
class Monster :public Character{
protected:
    Item weakness;// The weakness of the monster
    
public:
    Monster();
    Monster(std::string name, bool aliveStatus, Item weakness); // Constructor taking a string for name a bool value for alive or not and its weakness
    void say(); // output a sentence
    bool dead(std::string weapon);// checking the alive status
    void setWeakness(Item item); // set function for weakness
    Item getWeakness(); // get function for weakness
    ~Monster(); //destructure
};
#endif
