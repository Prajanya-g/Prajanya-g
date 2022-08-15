// Prajanya gupta 
// 25/03/22
// This a class for an implementation of the Furby
#ifndef FURBY_H
#define FURBY_H
#include "ArtificialPet.h"

class Furby: public ArtificialPet
{
public:
    void play(int minutes);
    void dance(int minutes);
};
#endif
