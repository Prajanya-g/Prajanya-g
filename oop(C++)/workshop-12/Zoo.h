#ifndef ZOO_H
#define ZOO_H
#include<iostream>
#include"Animal.h"
#include"Vegie.h"
#include"Hunter.h"
#include<string>

class Zoo{
public:
    Zoo(std::string n,int cows,int lions);      // create a zoo with the given number of cows and lions
    std::string get_name();
    int get_number();
    Animal** get_animals();

protected:
    std::string name ;                          // the zoo's name
    int number_of_animals ;                // the number of animals in the zoo
    Animal **animals ;                      // the zoo's animals
};
#endif


