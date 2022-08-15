// Prajanya gupta 
// 25/03/22
// The code defines the functions for the attributes for the ArtificialPet
#include "ArtificialPet.h"
#include <iostream>

ArtificialPet::ArtificialPet(){
    fullness = 10;
}

bool ArtificialPet::isHungry(){
    if(fullness<0){
        return true;
    }
    else{
        return false;
    }
}

void ArtificialPet::feed(){
    fullness = fullness+(((0.5)*(10-fullness))+1);
    if(fullness > 10){
        fullness = 10;
    }
    std::cout<<fullness<<std::endl;
}

void ArtificialPet::play(int minutes){
    //nothing
}
