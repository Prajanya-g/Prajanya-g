#include<string>
#include<iostream>
#include"Lightbox.h"

int main(void){
    Lightbox l1,l2("red",31),l3("blue",21);
    std::cout << "color "<< l1.get_colour() << "width "<<l1.get_width()<<std::endl;
    std::cout << "color "<< l2.get_colour() << "width "<<l2.get_width()<<std::endl;
    std::cout << "color "<< l3.get_colour() << "width "<<l3.get_width()<<std::endl;
}
