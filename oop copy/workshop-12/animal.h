#ifndef ANIMAL_H
#define ANIMAL_H
#include<iostream>
#include<string>

class Animal{
public:
    Animal(std::string n, int v) ;  // creates an animal with name n and body volume v.
                               // animals are allocated a unique ID on creation
    void set_name(std::string name); // set function name
    void set_volume(int volume);// set function volume
    int get_animalID();//get function animal id
    int get_volume();// get function volume
    virtual std::string get_name();// virtual get function name 
    
protected:
    std::string name ;              // the animal's name
    int animalID ;             // the animal's unique ID
    int volume ;
};
#endif

