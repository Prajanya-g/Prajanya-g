#include <iostream>
#include "Item.h"
#include "Monster.h"
#include "Character.h"
#include "Room.h"


int main()
{

    Item ring("RING", 500000);
    Item chalice("CHALICE", 500000);

    Monster medusa("Medusa",true,chalice);

    Room room5(5,&medusa,&medusa);

    room5.setDoorDirection("NORTH");
    room5.setDoorDirection("EAST");
    room5.setDoorDirection("SOUTH");

    room5.setCurrentItem(ring);
    room5.setCurrentItem(chalice);


    Item* itemsInRoom = room5.getCurrentItem();


    std::cout<< "This is room number:" << room5.getNumber() << std::endl;
    std::cout<< "There is " << room5.getMonster()->getName() << " in the room." <<std::endl;
    std::cout<< "There are "<<  room5.getNumberItem()<<" item(s) in the room: " <<std::endl;

    for (int i = 0; i < room5.getNumberItem(); i++)
        {
                std::cout<<itemsInRoom[i].getName()<<" ";
        }
    std::cout<<std::endl;
    room5.showDirections();



    return 0;
}
