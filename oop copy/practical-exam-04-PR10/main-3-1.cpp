#include<iostream>
#include<string>
#include"RecordStore.h"
#include"StoreChain.h"

int main(void){
    StoreChain c1;
    RecordStore** a1 = c1.get_chain();
    for(int i = 0; i < 5; i++){
    std::cout << "name " << a1[i]->get_name() << " address "<< a1[i]->get_address() << " sales "<< a1[i]->get_sales()<<std::endl;
    }
}
