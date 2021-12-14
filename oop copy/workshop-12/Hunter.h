#ifndef HUNTER_H
#define HUNTER_H
#include<iostream>
#include"Animal.h"
#include<string>

class Hunter :public Animal{
public:
    Hunter(std::string n, int v);
    void set_kill(int kills);
    int get_kill();
    
protected:
    int kills;
    static int nextID;
};
#endif
