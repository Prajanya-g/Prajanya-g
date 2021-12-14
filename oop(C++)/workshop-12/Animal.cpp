#include<iostream>
#include<string>
#include"Animal.h"

Animal::Animal(std::string n, int v){
    name = n;
    volume = v;
    animalID = 0;
}

void Animal::set_name(std::string name){
    this -> name = name;
}
void Animal::set_volume(int volume){
    this -> volume = volume;
}
int Animal::get_animalID(){
    return animalID;
}
int Animal::get_volume(){
    return volume;
}
std::string Animal::get_name(){
    return name;
}
