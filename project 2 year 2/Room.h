#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include "Item.h"
#include "Monster.h"
#include "Character.h"
#include <string>

// defining the room class
class Room{
private:
    int number; // the room number
    Character* currentCharacter; //  character in the room
    Monster* currentMonster; // monster in the room
    Item* currentItem;// pointer for all the item in the room
    int numberItem;// a count for items
    std::string* directionDoor; // the direction of the doors in the room
    int numberDoor;// count for the doors

public:
    Room();// constructor
    Room(int number, Character* person, Monster* monster);// parametertised constructor for room
    void setCurrentMonster(Monster* monster);// set function for monster
    Monster* getMonster();// get function for monster
    void setNumber(int number); // set function for number
    void setCurrentCharacters(Character* person);// set function for charaters
    void setCurrentItem(Item curItem);// set function for items
    void setDoorDirection(std::string Direction);// set function for doors
    int move(std::string direction);// method to check the room numbers user can move to
    Character* getCharacters();// get function for the characters
    Item* getCurrentItem();// get function for the items
    std::string* getDoors();// get function for the door
    int getNumberItem();// get function for number item
    int getNumber(); // get function for the room number
    void removeItem(Item curItem);// methid to remove an item
    void showDirections();//displays all the directions where doors are possible
    ~Room();//destructir
};
#endif
