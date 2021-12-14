#include "Character.h"
#include "Action.h"

int main()
{
    // Initialize character object
    Character character1("Someone", true);

    // Testing methods
    character1.say();
    std::cout << character1.getName() << std::endl;
    character1.changeStatus(false);
    std::cout << character1.getStatus() << std::endl;
}