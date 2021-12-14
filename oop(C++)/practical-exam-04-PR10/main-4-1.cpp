#include<iostream>
#include<string>
#include"RecordStores.h"
#include"Amoeba.h"

int main(void){
    Amoeba **chain;
    chain = new Amoeba*[5];
    chain[0] = new Amoeba("Store1");
    chain[1] = new Amoeba("Perth");
    chain[2] = new Amoeba("Adelaide");
    chain[3] = new Amoeba("Darwin");
    chain[4] = new Amoeba("Store2");
    RecordStores r1;
    r1.sort(chain,5);
}
