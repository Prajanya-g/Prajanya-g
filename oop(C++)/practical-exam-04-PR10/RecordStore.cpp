#include<iostream>
#include<string>
#include"RecordStore.h"


RecordStore::RecordStore(){
}
RecordStore::RecordStore(std::string n, std::string a, int s){
    name = n;
    address = a;
    sales = s;
}
void RecordStore::set_address(std::string address){
    this -> address = address;
}
std::string RecordStore::get_address(){
    return address;
}
void RecordStore::set_name(std::string name){
    this -> name = name;
}
std::string RecordStore::get_name(){
    return name;
}
void RecordStore::set_sales(int sales){
    this -> sales = sales;
}
int RecordStore::get_sales(){
    return sales;
}
int RecordStore::get_excessSales(){
    return 0;
}
