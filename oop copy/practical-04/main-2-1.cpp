#include <iostream>
#include "meerkat.h"
#include "cart.h"

using namespace std;

int main(void)
{
    meerkat m,m1,m2,m3,m4;
    
    m.setName("a");
    m.setAge(2);

    m1.setName("b");
    m1.setAge(20);
    
    m2.setName("c");
    m2.setAge(13);
    
    m3.setName("d");
    m3.setAge(32);
    
    m4.setName("e");
    m4.setAge(3);
    
    cart c1;
    
    c1.printMeerkats();
    
    c1.addMeerkat(m1);
    c1.addMeerkat(m2);
    c1.addMeerkat(m3);
    c1.addMeerkat(m4);
    c1.addMeerkat(m);
    
    c1.printMeerkats();
    
    return 0;
}

