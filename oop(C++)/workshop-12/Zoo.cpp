#include<iostream>
#include<string>
#include"Animal.h"
#include"Vegie.h"
#include"Hunter.h"
#include"Zoo.h"

Zoo::Zoo(std::string n,int cows,int lions){
    name = n;
    number_of_animals = cows+lions;
    animals = new Animal*[number_of_animals];
    Vegie *cow;
    cow = new Vegie("Daisy",100);
    Hunter *lion;
    lion = new Hunter("Clarence",50);
    for(int c = 0; c < cows; c++){
        animals[c] = cow;
    }
    for(int l = cows; l < lions; l++){
        animals[l] = lion;
    }
}
std::string Zoo::get_name(){
    return name;
}
int Zoo::get_number(){
    return number_of_animals;
}
Animal** Zoo::get_animals(){
    return animals;
}
