#include<iostream>
#include<string>
#include"Musician.h"

Musician::Musician(){
    years = 0;
    instrumentPlayed = "null";
}
Musician::Musician(std::string instrument, int experience){
    years = experience;
    instrumentPlayed = instrument;
}
std::string Musician::get_instrument(){
    return instrumentPlayed;
}
int Musician::get_experience(){
    return years;
}
Musician::~Musician(){}
