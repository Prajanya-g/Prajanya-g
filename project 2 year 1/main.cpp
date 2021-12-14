#include "Character.h"
#include "Item.h"
#include "Player.h"
#include "Monster.h"
#include "Action.h"
#include "Bag.h"
#include "Room.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <algorithm>

extern int userCommand(std::string functionName, std::string input, Room* currentRoom, Player* player);


int main(void)
{
    // Set color of the output to purple

    // creating the bag for the player
    Bag myBag;

    // creating the player
    Player player("player", true, &myBag);

    // creating all the items in the game
    Item shield("SHIELD", 0);
    Item dagger("DAGGER", 0);
    Item ring("RING", 500000);
    Item chalice("CHALICE", 500000);
    Item diamond("DIAMOND", 1000000);

    // creating the monsters in the game
    Monster medusa("MEDUSA", true, shield);
    Monster dracula("DRACULA", true, dagger);
    //creating a null monster
    Monster null("NULL", true, shield);
    // adding the princess
    Character princess("PRINCESS", true);

    // creating all the rooms array and adding room
    Room allRoom[9];
    Room room1(1,&null,&null);
    Room room2(2,&null,&null);
    Room room3(3,&null,&null);
    Room room4(4,&null,&null);
    Room room5(5,&medusa,&medusa);
    Room room6(6,&dracula,&dracula);
    Room room7(7,&null,&null);
    Room room8(8,&null,&null);
    Room room9(9,&princess,&null);

    // adding item to the room
    room2.setCurrentItem(ring);
    room3.setCurrentItem(shield);
    room4.setCurrentItem(chalice);
    room7.setCurrentItem(dagger);
    room8.setCurrentItem(diamond);

    // adding the direction of the connecting room
    room1.setDoorDirection("EAST");
    room1.setDoorDirection("SOUTH");
    room2.setDoorDirection("EAST");
    room2.setDoorDirection("SOUTH");
    room2.setDoorDirection("WEST");
    room3.setDoorDirection("WEST");
    room4.setDoorDirection("NORTH");
    room5.setDoorDirection("NORTH");
    room5.setDoorDirection("EAST");
    room5.setDoorDirection("SOUTH");
    room6.setDoorDirection("WEST");
    room6.setDoorDirection("SOUTH");
    room7.setDoorDirection("EAST");
    room8.setDoorDirection("WEST");
    room8.setDoorDirection("NORTH");
    room9.setDoorDirection("NORTH");

    // updating the array
    allRoom[0] = room1;
    allRoom[1] = room2;
    allRoom[2] = room3;
    allRoom[3] = room4;
    allRoom[4] = room5;
    allRoom[5] = room6;
    allRoom[6] = room7;
    allRoom[7] = room8;
    allRoom[8] = room9;


    std::cout<<"\t\t\t\t\t\t\t****************************"<<std::endl;
    std::cout<<"\t\t\t\t\t\t\t*   WELCOME TO ZELDA GAME  *"<<std::endl;
    std::cout<<"\t\t\t\t\t\t\t****************************"<<std::endl;

    // asking the user for the name
    std::string namePlayer;
    std::cout<< "Please enter your name: "<<std::endl;
    std::cin>>namePlayer;
    player.setName(namePlayer);
    std::cout << std::endl;

    // explaining the commands to the user
    std::cout<< "These are some basic commands: "<< std::endl;
    std::cout<< "move then a direction to move to a new room"<< std::endl;
    std::cout<< "pick then item name to pick an item"<< std::endl;
    std::cout<< "attack then monster to attack the monster"<<std::endl;
    std::cout<< "exit then \" Game \" to exit the game"<< std::endl;
    std::cout << std::endl;

    // creating variable current room
    Room* currentRoom = &allRoom[0];

    // Printing the instructions
    std::cout << "The princess of the kingdom of CPeria Princess Zelda. Has been captured by an evil wizard and placed in a castle guarded by monsters." << std::endl;
    std::cout << "Your job is to set her free and bring her back outside the castle." << std::endl;
    std::cout << "There are 9 rooms in the castle and one exit to it . Rooms have treasure and weapons too." << std::endl;
    std::cout << "so do you have the potential to destroy the monsters and save Princess Zelda ?" << std::endl;
    std::cout << "Are you ready " << player.getName() << "? " << std::endl;
    std::cout << "Lets do it !!" << std::endl;

    std::cout << std::endl;
    std::cout<< "To win the game reach room 9 and type exit game command"<< std::endl;
    std::cout << std::endl;

    std::cout << "Currently you are in Room 1. Navigate to different rooms and find items to defeat the monster and rescue the princess." << std::endl;

    currentRoom->showDirections();
    myBag.display();

    // creating 2 varuable to store the function and the inputs
    std::string input = " ";
    std::string function = " ";

    // unless the player types exit, the games runs
    while(function != "NEXIT")
    {
        std::cout << std::endl;
        std::cout <<"What do you want to do : ";
        std::cin >> function >> input;

        // converting to uppercase
        transform(function.begin(), function.end(), function.begin(), ::toupper);
        transform(input.begin(), input.end(), input.begin(), ::toupper);

        // performing different action based on the user command
        int roomNumber = userCommand(function, input, currentRoom, &player);

        // changing the room if the user types move
        if(function == "MOVE")
        {
            if (roomNumber != 0)
            {
               currentRoom = &allRoom[roomNumber-1];
            }

            // Show the room number and display the items in that room
            std::cout<<"You're currently in room "<<currentRoom->getNumber()<<std::endl;
            Item* itemsInRoom = currentRoom->getCurrentItem();
            std::cout<<"There are "<<currentRoom->getNumberItem()<<" item(s) in the room: ";
            for (int i = 0; i < currentRoom->getNumberItem(); i++)
            {
                std::cout<<itemsInRoom[i].getName()<<" ";
            }
            std::cout<<std::endl;

            // Display the character in the room
            // not printing if the character is null
            Character* characterInRoom = currentRoom->getCharacters();
            if (characterInRoom->getName() != "NULL" && characterInRoom->getStatus() == "Still Alive")
            {
                std::cout<<"There is the "<<characterInRoom->getName()<<" in the room."<<std::endl;
                characterInRoom->say();
            }
            else
            {
                std::cout<<"No one in the room."<<std::endl;
            }

            // Show the room directions connected to other room
            currentRoom->showDirections();
        }
        // displaying the items in the bag
        player.getBag()->display();
    }
}
