#ifndef AMOEBA_H
#define AMOEBA_H
#include<iostream>
#include<string>
#include"RecordStore.h"

class Amoeba: public RecordStore{
public:
    Amoeba(std::string a);         // creates address with a
    int get_excessSales();
    int get_storeID();
    void set_storeID(int storeID);
    int get_amoebaBranch();
    void set_amoebaBranch(int amoebaBranch);
    
protected:
    int storeID;                 // unique id for the store

private:
    static int amoebaBranch;
};
#endif



