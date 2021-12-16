#include "Bag.h"
#include "Character.h"
#include "Item.h"
#include "Player.h"


int main()
{
    // Initialize item for weakness
    Bag* bag;
    // Initialize character object
    Player player("", true, bag);
    // Testing the abstract method
    player.say();    
    // Testing methods inherited from Character
    std::cout << player.getName() << std::endl;
    std::cout << player.getStatus() << std::endl;
    // Testing its own methods
    Bag* player_bag = player.getBag();
    player_bag->display();
    player.setName("New name");
    std::cout << player.getName() << std::endl;
}