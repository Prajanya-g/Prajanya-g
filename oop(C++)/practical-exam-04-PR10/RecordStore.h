#ifndef RECORDSTORE_H
#define RECORDSTORE_H
#include<iostream>
#include<string>

class RecordStore{
public:
    RecordStore();
    RecordStore(std::string n, std::string a, int s);// creates a record store of name n, address a, and sales s
    void set_address(std::string address);
    std::string get_address();
    void set_name(std::string name);
    std::string get_name();
    void set_sales(int sales);
    int get_sales();
    virtual int get_excessSales(); // return the number of record sales above a given store target
    
protected:
    std::string name;           // the name of a record store
    std::string address;             // the address of a record store
    int sales;        // number of records that have been sold. Takes only non-negative
};
#endif


