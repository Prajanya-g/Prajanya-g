#include "Player.h"
#include "Bag.h"
#include <iostream>

// Constructor that takes a string as name, bool as alive status and a Bag object as myBag
Player::Player(std::string name, bool aliveStatus, Bag* myBag)
    :Character(name, aliveStatus)
{
    this->myBag = myBag;
}

// Virtual function say()
void Player::say()
{
    std::cout << "I am here!!" << std::endl;
}

// Set the name for the player
void Player::setName(std::string name)
{
    this->name = name;
}

// Return the object of the Bag class of the player
Bag* Player::getBag()
{
    return myBag;
}

// Set the bag for the player
void Player::setBag(Bag* myBag)
{
    this->myBag = myBag;
}

// Deconstructor for Player object
Player::~Player(){}

