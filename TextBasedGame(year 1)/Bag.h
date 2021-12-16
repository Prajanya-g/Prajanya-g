#ifndef BAG_H
#define BAG_H
#include <iostream>
#include "Item.h"

// defining bag object
class Bag{
private:
    int currentCount; // count of the objects
    Item inventory[10];// array of the items in the bag

public:
    Bag();// constructor
    void pick(Item object);// addding items to the bag
    void display();// displaying all the items in the bag
    bool checkItem(Item item);// check if we have the item in the bag
    ~Bag();// destructor
};
#endif
