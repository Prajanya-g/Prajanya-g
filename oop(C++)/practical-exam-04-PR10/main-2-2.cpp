#include<iostream>
#include<string>
#include"AmoebaTickets.h"
#include"Amoeba.h"

int main(void){
    AmoebaTickets a1;
    AmoebaTickets a2("asd");
    a2.sellTicket();
    std::cout << "name " << a1.get_name() << " address "<< a1.get_address() << " sales "<< a1.get_sales()<< " id " << a1.get_storeID() << " excess sale " << a1.get_excessSales()<< " ticket sold "<< a1.get_ticketsSold() <<std::endl;
    
    std::cout << "name " << a2.get_name() << " address "<< a2.get_address() << " sales "<< a1.get_sales()<< " id " << a2.get_storeID() << " excess sale " << a2.get_excessSales()<< " ticket sold "<< a2.get_ticketsSold() <<std::endl;
}
