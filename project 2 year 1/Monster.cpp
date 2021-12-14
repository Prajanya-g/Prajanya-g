#include "Monster.h"
#include "Item.h"
#include <iostream>
#include <algorithm>

// Default constructure
Monster::Monster(){
    name = "";
    aliveStatus = true;
}

// Constructure that takes a string as name, bool as alive status and a Item object weakness
Monster::Monster(std::string name, bool aliveStatus, Item weakness)
    :Character(name, aliveStatus)
{
    this->weakness = weakness;
}

// Virtual function say()
void Monster::say()
{
    std::cout << name << ": You cannot defeat me !!" << std::endl;
}

// This function is to attack the monster. If the name of the weapon is matching with the name
// of the monster weakness, the monster is killed.
bool Monster::dead(std::string weapon)
{
    if(weapon == weakness.getName()){
        aliveStatus = false;
        return true;
    }
    else{
        return false;
    }
}

// Set the attribute weakness of a monster
void Monster::setWeakness(Item item)
{
    this->weakness = item;
}

// Get the weakness of the monster
Item Monster::getWeakness()
{
    return weakness;
}

// Destructor for the Monster object
Monster::~Monster(){}
