#include<iostream>
#include<string>
#include"Animal.h"

int main(void){
    Animal tiger("tiger",23);
    Animal lion("lion",21);
    std::cout << "name " << tiger.get_name()<<" volume "<<tiger.get_volume()<<" id"<<tiger.get_animalID()<<std::endl;
    lion.set_name("cat");
    lion.set_volume(123);
    std::cout << "name " << lion.get_name()<<" volume "<<lion.get_volume()<<" id"<<lion.get_animalID()<<std::endl;
}
