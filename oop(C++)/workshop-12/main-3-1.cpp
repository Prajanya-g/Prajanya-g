#include<iostream>
#include<string>
#include"Animal.h"
#include"Vegie.h"
#include"Hunter.h"
#include"Zoo.h"

int main(void){
    Zoo a("abc",2,2);
    Animal **animals = a.get_animals();
    std::cout << "name " << animals[0]->get_name()<<" volume "<<animals[0]->get_volume()<<" id"<<animals[0]->get_animalID()<< std::endl;
    animals[0]->set_food("a");
}



