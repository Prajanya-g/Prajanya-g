#include<iostream>
#include<string>
#include"Animal.h"
#include"Hunter.h"

int main(void){
    Hunter tiger("tiger",23);
    Hunter lion("lion",21);
    tiger.set_kill(2);
    lion.set_kill(10);
    std::cout << "name " << tiger.get_name()<<" volume "<<tiger.get_volume()<<" id"<<tiger.get_animalID()<< " kill " << tiger.get_kill()<<std::endl;
    lion.set_name("cat");
    lion.set_volume(123);
    std::cout << "name " << lion.get_name()<<" volume "<<lion.get_volume()<<" id"<<lion.get_animalID()<< " kill " << lion.get_kill()<<std::endl;
}

