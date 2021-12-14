#include<iostream>
#include<string>
#include"Animal.h"
#include"Vegie.h"

int Vegie::nextID = 100;

Vegie::Vegie(std::string n, int v):Animal(n,v){
    animalID = nextID;
    nextID++;
}
void Vegie::set_food(std::string favourite_food){
    this-> favourite_food = favourite_food;
}
std::string Vegie::get_food(){
    return favourite_food;
}

