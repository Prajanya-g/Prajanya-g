#include <iostream>
#include "Character.h"
#include "Item.h"
#include "Room.h"

//constructor for Room
Room::Room()
{
    number=0;
    numberItem=0;
    numberDoor=0;
}

//constructor for Room with some parameters to initialize values of some members
Room::Room( int number, Character* person, Monster* monster)
{
    this -> number = number;
    currentCharacter = person;
    currentMonster = monster;
    numberItem=0;
    numberDoor=0;
    directionDoor = new std::string[4];
    currentItem = new Item[5];

}
//Function for setting the room number
void Room::setNumber(int number)
{
    this->number=number;       //sets the value of variable equal to the input parameter
}

//Function for adding the Character to the room
void Room::setCurrentCharacters(Character* person)
{
    currentCharacter=person;
}

//Function for adding the Items that are in the room to the currentItem array
void Room::setCurrentItem(Item curItem)
{
    *(currentItem+numberItem)= curItem;
    numberItem++;
}

//Function for adding the directions in which doors are available to move in different rooms
void Room::setDoorDirection(std::string direction)
{
    *(directionDoor+numberDoor)=direction;             //* allows to access the elements that is being pointed to by the pointer in the brackets and set
                                                       //value of it equal to the input parameter.
    numberDoor++;
}

//Function to remove the Item that we have picked from the item array
void Room::removeItem(Item curItem)
{
    // using for loop to surf thorugh all the items in the inventory
    for (int index = 0; index < numberItem; index++)
    {
        Item temp;
        temp.setName(currentItem[index].getName());
        if (temp.getName() == curItem.getName())
        {
            // shifting all the remaining element to the front
            for(int j = index; j <( numberItem); j++)
            {
                currentItem[j]=currentItem[j+1];
            }
            // reducing the count
            numberItem--;
            std::cout<<"Item removed from the room successfully"<<std::endl;
            break;
        }
        // printing a message if the element not found
        else
        {
            std::cout<<"Element not found"<<std::endl;
        }
    }
}


//Function to check if the move is possible in the entered direction
int Room::move(std::string direction)
{
    if(number==1)
    {
        if(direction=="EAST")
        {
            return 2;
        }
        else if(direction=="SOUTH")
        {
            return 4;
        }
        else
        {
            return 0;
        }
    }

    if(number==2)
    {
        if(direction=="EAST")
        {
            return 3;
        }
        else if(direction=="SOUTH")
        {
            return 5;
        }
        else if(direction=="WEST")
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    if(number==3)
    {
        if(direction=="WEST")
        {
            return 2;
        }
        else
        {
            return 0;
        }
    }

    if(number==4)
    {
       if(direction=="NORTH")
       {
           return 1;
       }
       else
       {
           return 0;
       }
    }

    if(number==5)
    {
        if(direction=="NORTH")
        {
            return 2;
        }
        else if(direction=="EAST")
        {
            return 6;
        }
        else if(direction=="SOUTH"&& currentCharacter->getStatus()=="Died")
        {
            return 8;
        }
        else if(direction=="SOUTH"&& currentCharacter->getStatus()=="Still Alive")
        {
            std::cout<<"This room is locked. Defeat the monster to enter this room."<<std::endl;
            return 0;
        }
        else
        {
            return 0;
        }
    }

    if(number==6)
    {
        if(direction=="WEST")
        {
            return 5;
        }
        else if(direction=="SOUTH" && currentCharacter->getStatus()=="Died")
        {
            return 9;
        }
        else if(direction=="SOUTH" && currentCharacter->getStatus()=="Still Alive")
        {
            std::cout<<"This room is locked. Defeat the monster to enter this room."<<std::endl;
            return 0;
        }
        else
        {
            return 0;
        }
    }

    if(number==7)
    {
        if(direction=="EAST")
        {
            return 8;
        }
        else
        {
            return 0;
        }
    }

    if(number==8)
    {
        if(direction=="WEST")
        {
            return 7;
        }
        else if(direction=="NORTH")
        {
            return 5;
        }
        else
        {
            return 0;
        }
    }

    if(number==9)
    {
        if(direction=="NORTH")
        {
            return 6;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}

//function to show all the possible directions in which doors are available
void Room::showDirections()
{
    for(int i=0;i<numberDoor;i++)
    {
        std::cout<< "There is a room to your: "<< *(directionDoor+i) <<"."<<std::endl;
    }
}

//Function to get all the character that are in the room
Character* Room::getCharacters()
{
    return currentCharacter;
}

//Function to get all the items in the room
Item* Room::getCurrentItem()
{
    return currentItem;
}

//Function to get all the directions where there is a door
std::string* Room::getDoors()
{
    return directionDoor;
}

//Function to get the room number you are currently in
int Room::getNumber()
{
   return number;
}

//Function to get the number of items in the room
int Room::getNumberItem()
{
    return numberItem;
}

//Function to set the monsters in the room
void Room::setCurrentMonster(Monster* monster){
    currentMonster = monster;
}

//Function to get the monster in the room
Monster* Room::getMonster(){
    return currentMonster;
}

//Default destructor
Room::~Room()
{

}
