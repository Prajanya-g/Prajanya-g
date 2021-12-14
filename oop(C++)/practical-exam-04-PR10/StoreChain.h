#ifndef STORECHAIN_H
#define STORECHAIN_H
#include<iostream>
#include<string>
#include"RecordStore.h"

class StoreChain{
public:
    StoreChain();
    RecordStore **get_chain();
protected:
    RecordStore **chain;
};
#endif






