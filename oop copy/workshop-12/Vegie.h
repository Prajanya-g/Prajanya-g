#ifndef VEGIE_H
#define VEGIE_H
#include<iostream>
#include"Animal.h"
#include<string>

class Vegie :public Animal{
public:
    Vegie(std::string n, int v);
    void set_food(std::string favourite_food);
    std::string get_food();
    
protected:
    std::string favourite_food;
    static int nextID;
};
#endif

