#include <iostream>
#include "person.h"
#include "aircraft.h"

using namespace std;

int main(void)
{
    person m("s",123),m1,m2;

    m1.setName("a");
    m1.setSalary(321);
    
    m2.setName("b");
    m2.setSalary(322311);
    
    aircraft a1("a123",m,m1);
    a1.printDetails();
    
    return 0;
}


