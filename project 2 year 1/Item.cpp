#include<iostream>
#include<string>
#include"Item.h"

// Default constructor for Item
Item::Item(){
    name = "??";
    value = 0;
}

// Constructor with parameters
Item::Item(std::string name, int value)
{
    this->name = name;
    this->value = value;
}

// The function is a set function for value
// The function has a parameter that takes in the value
// The function doesn't return anything
void Item::setValue(int value){
    this ->value = value;
}

// The function is a set function for name
// The function has a parameter that takes in the name
// The function doesn't return anything
void Item::setName(std::string name){
    this ->name = name;
}

//The function is a get function for name
// The function has no parameter
// The function returns the name of the item
std::string Item::getName(){
    return name;
}

//The function is a get function for value
// The function has no parameter
// The function returns the value of the item
int Item::getValue(){
    return value;
}

// destructor for Item
Item::~Item(){
}

