#include<string>
#include<iostream>
#include"Lightbox.h"
#include"Shelf.h"

int main(void){
    Lightbox l1,l2("red",10),l3("blue",10),l4("black",10);
    Shelf s1(20);
    std::cout<<"width: "<< s1.get_width()<<std::endl;
    s1.add_lightbox(l2);
    std::cout<<"length: "<< s1.get_currentLength()<<std::endl;
    s1.add_lightbox(l3);
    std::cout<<"length: "<< s1.get_currentLength()<<std::endl;
    s1.add_lightbox(l4);
    s1.add_lightbox(l1);
    std::cout<<"count: "<< s1.get_number_of_lightboxes()<<std::endl;
    int size = s1.get_count();
    Lightbox* l = s1.get_contents();
    for (int index = 0 ; index < size; index++) {
        std::string temp = l[index].get_colour();
        std::cout<<temp<<" "<<std::endl;
    }
}
