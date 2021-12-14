#include<iostream>
#include<string>
#include"AmoebaTickets.h"
#include"Amoeba.h"

AmoebaTickets::AmoebaTickets():Amoeba(""){
    ticketsSold =0;
}
AmoebaTickets::AmoebaTickets(std::string n):Amoeba(""){
    ticketsSold =0;
    name = n;
}
void AmoebaTickets::sellTicket(){
    ticketsSold++;
}
int AmoebaTickets::get_ticketsSold(){
    return ticketsSold;
}
