#include<iostream>
#include"aircraft.h"
#include<string>
#include"person.h"

aircraft::aircraft(std::string callsign,person thePilot,person theCoPilot){
    csign = callsign;
    pilot = thePilot;
    coPilot = theCoPilot;
}
void aircraft::setPilot(person thePilot){
    pilot = thePilot;
}
person aircraft::getPilot(){
    return pilot;
}
void aircraft::setCoPilot(person theCoPilot){
    coPilot = theCoPilot;
}
person aircraft::getCoPilot(){
    return coPilot;
}
void aircraft::printDetails(){
    std::cout << csign << std::endl;
    std::cout << pilot.getName() << std::endl;
    std::cout << coPilot.getName() << std::endl;
}
aircraft::~aircraft(){
    
}
