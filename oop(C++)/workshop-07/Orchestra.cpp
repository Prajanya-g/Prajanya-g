#include<iostream>
#include"orchestra.h"
#include<string>
#include"Musician.h"

Orchestra::Orchestra(){
    size = 0;
    count = 0;
}
Orchestra::Orchestra(int size){
    this->size = size;
    count = 0;
    musician = new Musician[size];
}
int Orchestra::get_current_number_of_members(){
    return count;
}
bool Orchestra::has_instrument(std::string instrument){
    for(int index = 0; index<count;index++){
        std::string temp = musician[index].get_instrument();
        if(temp== instrument){
            return true;
        }
    }
    return false;
}
Musician* Orchestra::get_members(){
    return musician;
}
bool Orchestra::add_musician(Musician new_musician){
    if(count == size){
        return false;
    }
    musician[count] = new_musician;
    count++;
    return true;
}
Orchestra::~Orchestra(){
    delete[] musician;
}
