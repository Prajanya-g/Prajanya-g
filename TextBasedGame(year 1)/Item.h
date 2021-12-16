#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>

// defining item object
class Item{
protected:
    std::string name;// name of the item
    int value;// value of the item
    
public:
    Item();// constructor
    Item(std::string name, int value); // constructor with parameters
    void setValue(int value);//set function for value
    void setName(std::string name);// set function for name
    std::string getName();// get function for name
    int getValue();// get function for value
    ~Item();//destructor
};
#endif

