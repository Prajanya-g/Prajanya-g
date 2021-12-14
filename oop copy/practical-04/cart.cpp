#include<iostream>
#include"cart.h"
#include<string>
#include"meerkat.h"

cart::cart(){
    passenger = 0;
}
bool cart::addMeerkat(meerkat cat){
    if(passenger == 4){
        return false;
    }
    meerkatCart[passenger] = cat;
    passenger++;
    return true;
}
void cart::emptyCart(){
    passenger = 0;
}
void cart::printMeerkats(){
    for(int index = 0; index < passenger; index++){
        meerkat temp;
        temp.setName(meerkatCart[index].getName());
        temp.setAge(meerkatCart[index].getAge());
        std::cout << temp.getName() << " "<< temp.getAge() << std::endl;
    }
}
cart::~cart(){
    
}
