// Prajanya gupta 
// 25/03/22
// The code defines the functions for the attributes for the Furby
#include "ArtificialPet.h"
#include "Furby.h"

void Furby::play(int minutes){
    fullness = fullness - (2*minutes);
}

void Furby::dance(int minutes){
     fullness = fullness - (3*minutes);
}