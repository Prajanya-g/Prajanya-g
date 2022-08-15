// Prajanya gupta 
// 15/03/22
// This a class for an implementation of the ArtificialPet 
#ifndef ARTIFICIALPET_H
#define ARTIFICIALPET_H

class ArtificialPet
{
protected:
    int fullness;
public:
    ArtificialPet();
    bool isHungry(); // hungry when fullness is negative not hungey when fullness is 10 return bool
    void feed();//increases the fullness level of the pet by 1/2 of (the current difference between the pet's fullness and the maximum fullness of 10) + 1 
    virtual void play(int minutes);
};
#endif
