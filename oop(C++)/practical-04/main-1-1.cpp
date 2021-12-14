#include <iostream>
#include "meerkat.h"

using namespace std;

int main(void)
{
    meerkat m, m1,m2,m3;

    cout << "name: " << m.getName() << ", age: ";
    cout << m.getAge() << endl;

    m1.setName("a");
    m1.setAge(20);

    cout << "name: " << m1.getName() << ", age: ";
    cout << m1.getAge() << endl;
    
    m2.setName("b");
    m2.setAge(13);

    cout << "name: " << m2.getName() << ", age: ";
    cout << m2.getAge() << endl;
    
    m3.setName("c");
    m3.setAge(32);

    cout << "name: " << m3.getName() << ", age: ";
    cout << m3.getAge() << endl;
    
    return 0;
}
