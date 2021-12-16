#include <iostream>
#include <algorithm>
#include "Bag.h"
#include "Item.h"


// default constructor for the bag
Bag::Bag(){
    currentCount=0;
    Item inventory[10];
}

// The function add items to the invertory
// The function does not return any varibale
// The function has a parameter the item
void Bag::pick(Item object){
    // adding the object to the inventory 
    inventory[currentCount]=object;
    currentCount++;
    std::cout<<"Item added to the bag successfully"<<std::endl;
}

// The function prints all the items in the bag
// The function does not return any varibale
// The function has no parameter
void Bag::display(){
    std::cout<<"The bag contains: "<< currentCount <<std::endl;
    if(currentCount == 0){
        std::cout << "Currently, your bag is empty." << std::endl;
    }
    // using for loop to go throught all the value in the inventory
    for (int index = 0; index < currentCount; index++) {
        Item item;
        item.setName(inventory[index].getName());
        item.setValue(inventory[index].getValue());
        std::cout << "name: " << item.getName() << ", value: ";
        std::cout << item.getValue() << std::endl;
    }
    int cash = 0;
      for (int index = 0; index < currentCount; index++)
      {
          cash = cash + inventory[index].getValue();
      }
    std::cout<< "Current Cash : " << cash << std::endl;
}
// The function checks if we have the item in the room
// The function return true of the item is present else false
// The function has one parameter the item we need to check
bool Bag::checkItem(Item item){
    for (int index = 0; index < currentCount; index++) {
        // checking the names of the items
        if(inventory[index].getName() == item.getName()){
            return true;
        }
    }
    return false;
}

// destructor for bag
Bag::~Bag(){
}
