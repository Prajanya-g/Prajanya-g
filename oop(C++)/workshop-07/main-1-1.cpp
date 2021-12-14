#include<iostream>
#include<string>
#include"Musician.h"

int main(void){
    Musician m,m2("b",4),m1("a",3);
    
    std::cout << "years: " << m.get_experience() << "intrument: " << m.get_instrument()<<std::endl;
    std::cout << "years: " << m1.get_experience() << "intrument: " << m1.get_instrument()<<std::endl;
    std::cout << "years: " << m2.get_experience() << "intrument: " << m2.get_instrument()<<std::endl;
}
