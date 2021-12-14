#include "Character.h"
#include "Item.h"
#include "Monster.h"

int main()
{
    // Initialize item for weakness
    Item weakness("gun", 0);
    // Initialize character object
    Monster monster("Monster1", true, weakness);
    // Testing the abstract method
    monster.say();    
    // Testing methods inherited from Character
    std::cout << monster.getName() << std::endl;
    std::cout << monster.getStatus() << std::endl;
    // Testing its own methods
    Item monster_weakness = monster.getWeakness();
    std::cout << monster_weakness.getName() << std::endl;
    std::cout << monster.dead("gun") << std::endl;
}