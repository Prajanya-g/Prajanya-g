#include<iostream>
#include<string>
#include"RecordStore.h"
#include"Amoeba.h"

int main(void){
    Amoeba a1("abas");
    Amoeba a2("sad");
    a1.set_sales(1230);
    a2.set_sales(123);
    std::cout << "name " << a1.get_name() << " address "<< a1.get_address() << " sales "<< a1.get_sales()<< " id " << a1.get_storeID() << " excess sale " << a1.get_excessSales()<< std::endl;
    std::cout << "name " << a2.get_name() << " address "<< a2.get_address() << " sales "<< a1.get_sales()<< " id " << a2.get_storeID() << " excess sale " << a2.get_excessSales()<< std::endl;
}

