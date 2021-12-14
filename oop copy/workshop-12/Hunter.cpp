#include<iostream>
#include<string>
#include"Animal.h"
#include"Hunter.h"

int Hunter::nextID = 1000;

Hunter::Hunter(std::string n, int v):Animal(n,v){
    animalID = nextID;
    nextID++;
}
void Hunter::set_kill(int kills){
    this-> kills = kills;
}
int Hunter::get_kill(){
    return kills;
}
