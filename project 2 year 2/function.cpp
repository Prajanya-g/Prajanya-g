#include "Character.h"
#include "Item.h"
#include "Player.h"
#include "Monster.h"
#include "Action.h"
#include "Bag.h"
#include "Room.h"
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string>

// the function execute the user commands- move, attack, pick and exit based on the inputs and update the data
// the function return an integer value representing the room number. the value 0 represents that the player is still in the same room
// The function has four parameter the function name and the input associated with it then the current room and the player
int userCommand(std::string functionName, std::string input, Room* currentRoom, Player* player)
{
    // Checking the different function name and performing function accordingly
    if (functionName == "MOVE")
    {
        // checking for wrong input
        if(input != "EAST" && input != "WEST" &&  input != "NORTH" &&  input != "SOUTH"){
            std::cout<<"wrong input"<<std::endl;
            return 0;
        }
        // changing the room based on the user iniput
        int changedRoom = currentRoom->move(input);
        return changedRoom;
    }

    if (functionName == "ATTACK")
    {
        // checking if the character entered is princess
        Character* character = currentRoom->getCharacters();
        if (character->getName() == "PRINCESS")
        {
            std::cout << "You cannot attack her!" << std::endl;
            return 0;
        }
        // checkign if the monster is present in the room
        Monster* monster = currentRoom->getMonster();
        if(input != monster->getName()){
            std::cout<< input<<" not in the room"<< std::endl;
            return 0;
        }

        // checking if the monster is alive or dead
        if (monster->getStatus() == "Died") {
            std::cout << "The monster was dead." << std::endl;
            return 0;
        }
        // checking if the weapon to kill the monster is in the bag
        Item weapon = monster->getWeakness();
        if (player->getBag()->checkItem(weapon) == 1)
        {
            std::cout<< monster->getName()<<" is dead"<<std::endl;
            monster->dead(weapon.getName());
        }
        else
        {
            std::cout<<"You didn't have the item to kill the monster. Game over!"<<std::endl;
            exit(0);
        }
        return 0;
    }


    if (functionName == "PICK")
    {
        Item* items = currentRoom->getCurrentItem();
        for (int i = 0; i < currentRoom->getNumberItem(); i++)
        {
            //checking if there is a item matching the input
            if (items[i].getName() == input)
            {
                player->getBag()->pick(items[i]);
                currentRoom->removeItem(items[i]);
                return 0;
            }
            else
            {
                std::cout <<  "Item not in the room" << std::endl;
                return 0;
            }
        }
        std::cout << "item not in the room"<<std::endl;
        return 0;
    }

    if (functionName == "EXIT" && input == "GAME")
    {
        // if in the room 9 the player win a message is displayed and game is exit
        if (currentRoom->getNumber() == 9)
        {
            std::cout<<"You rescued the princess. You win!"<<std::endl;
        }
        else
        {
            // asking if the user is sure and executing the commands accordingly
            std::cout <<  "Are you sure? (Type 'Y' if yes, otherwise type anything): ";
            std::string userResponse;
            std::cin >> userResponse;
            transform(userResponse.begin(), userResponse.end(), userResponse.begin(), ::toupper);
            if (userResponse != "Y")
            {
                return 0;
            }
            if(userResponse=="Y")
            {
                std::cout<<"You have ended the game. Game over!"<<std::endl;
            }
        }
        exit(0);
    }
    std::cout<<"Please Check the input"<<std::endl;
    return 0;
}
