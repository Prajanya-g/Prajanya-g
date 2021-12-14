#include<iostream>
#include<string>
#include"Animal.h"
#include"Vegie.h"

int main(void){
    Vegie tiger("tiger",23);
    Vegie lion("lion",21);
    tiger.set_food("a");
    lion.set_food("b");
    std::cout << "name " << tiger.get_name()<<" volume "<<tiger.get_volume()<<" id"<<tiger.get_animalID()<< " food " << tiger.get_food()<<std::endl;
    lion.set_name("cat");
    lion.set_volume(123);
    std::cout << "name " << lion.get_name()<<" volume "<<lion.get_volume()<<" id"<<lion.get_animalID()<< " food " << lion.get_food()<<std::endl;
}


