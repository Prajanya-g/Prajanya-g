#include<iostream>
#include"orchestra.h"
#include<string>
#include"Musician.h"


int main(void){
    Musician m,m2("b",4),m1("a",3);
    Orchestra o(3);
    o.add_musician(m);
    o.add_musician(m1);
    o.add_musician(m2);
    std::cout<<o.has_instrument("b")<<std::endl;
    int size = o.get_current_number_of_members();
    Musician *m4=  o.get_members();
    for (int index = 0 ; index < size; index++) {
        std::string temp = m4[index].get_instrument();
        std::cout<<temp<<" "<<std::endl;
    }
}

