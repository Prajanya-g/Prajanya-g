#include "ArtificialPet.h"
#include "Furby.h"
#include <iostream>

int main(void){
    Furby f;
    std::cout<< f.isHungry() << std::endl;
    f.play(1);
    f.dance(3);
    std::cout<< f.isHungry() << std::endl;
    f.feed();
    f.feed();
    f.feed();
}