#include <iostream>
#include "person.h"

using namespace std;

int main(void)
{
    person m("s",123),m1,m2,m3;

    cout << "name: " << m.getName() << ", salary: ";
    cout << m.getSalary() << endl;

    m1.setName("a");
    m1.setSalary(321);

    cout << "name: " << m1.getName() << ", salary: ";
    cout << m1.getSalary() << endl;
    
    m2.setName("b");
    m2.setSalary(322311);

    cout << "name: " << m2.getName() << ", salary: ";
    cout << m2.getSalary() << endl;
    
    m3.setName("c");
    m3.setSalary(321213);

    cout << "name: " << m3.getName() << ", salary: ";
    cout << m3.getSalary() << endl;
    
    return 0;
}

