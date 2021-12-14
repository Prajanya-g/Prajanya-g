#include "Character.h"
#include <iostream>
#include <stdlib.h>
#include "Action.h"

Character::Character(){
    name = " ";
    aliveStatus = true;
}
// constructor for the character class
// The functoin doesnt return anything
// The function has two parameters the name and the alive status for the character
Character::Character(std::string name, bool aliveStatus){
    this->name = name;
    this->aliveStatus = aliveStatus;
}

// The function is a vritual function that prints a messsage
// The function does not return anything
// There are no parameter for the function
void Character::say(){
    std::cout<<"I am " << name << ". "<< std::endl;
}

// The function changes the alivestatus for the character
// The function doesnt return any variable
// The function has a parameter the new status
void Character::changeStatus(bool status){
    aliveStatus = status;
}

// The function prints message based on the alive status of the character
// The function doesnt return any variable
// The function has no parameter
std::string Character::getStatus(){
    if (aliveStatus){
        return "Still Alive";
    }
    else{
        return "Died";
    }
}

// The function is a get functiong of name
// The function returns the name
// The function has no parameter
std::string Character::getName(){
    return name;
}

// desturtor 
Character::~Character(){}

