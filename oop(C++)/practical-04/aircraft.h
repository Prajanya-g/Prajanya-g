#ifndef AIRCRAFT_H
#define AIRCRAFT_H
#include<string>
#include"person.h"

class aircraft : public person{
public:
    aircraft(std::string callsign,person thePilot,person theCoPilot);
    void setPilot(person thePilot);
    person getPilot();
    void setCoPilot(person theCoPilot); 
    person getCoPilot();
    void printDetails();
    ~aircraft();
    
private:
    std::string csign;
    person pilot;
    person coPilot;
};
#endif

