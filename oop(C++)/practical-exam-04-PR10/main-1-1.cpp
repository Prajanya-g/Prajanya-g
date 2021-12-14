#include<iostream>
#include<string>
#include"RecordStore.h"

int main(void){
    RecordStore s1("a","a2",32);
    RecordStore s2;
    std::cout << "name " << s1.get_name() << " address "<< s1.get_address() << " sales "<< s1.get_sales()<<std::endl;
    std::cout << "name " << s2.get_name() << " address "<< s2.get_address() << " sales "<< s2.get_sales()<<std::endl;
    s2.set_name("ab");
    s2.set_address("asddd");
    s2.set_sales(123);
    std::cout << "name " << s2.get_name() << " address "<< s2.get_address() << " sales "<< s2.get_sales()<<std::endl;
}
