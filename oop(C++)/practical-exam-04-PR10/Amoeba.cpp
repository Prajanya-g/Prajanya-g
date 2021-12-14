#include<iostream>
#include<string>
#include"RecordStore.h"
#include"Amoeba.h"

int Amoeba::amoebaBranch = 0;

Amoeba::Amoeba(std::string a):RecordStore("Amoeba",a,0){
    storeID = amoebaBranch;
    amoebaBranch++;
}
int Amoeba::get_excessSales(){
    if(sales <= 1000){
        return 0;
    }
    else{
        return sales-1000;
    }
}
int Amoeba::get_storeID(){
    return storeID;
}
void Amoeba::set_storeID(int storeID){
    this -> storeID = storeID;
}
int Amoeba::get_amoebaBranch(){
    return amoebaBranch;
}
void Amoeba::set_amoebaBranch(int amoebaBranch){
    this ->amoebaBranch = amoebaBranch;
}
