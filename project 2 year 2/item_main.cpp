#include <iostream>
#include "Item.h"

using namespace std;

int main(void)
{
    // creating three items one using default constructor and other using parameterised constructor
    Item i,i1("item2",231),i2("item3",321);
    //displaying the output
    cout << "name: " << i.getName() << ", value: ";
    cout << i.getValue() << endl;
    //Testing the set function in the default constructor
    i.setName("item1");
    i.setValue(213);
    //displaying the outputs for two items
    cout << "name: " << i.getName() << ", value: ";
    cout << i.getValue() << endl;
    cout << "name: " << i.getName() << ", value: ";
    cout << i.getValue() << endl;
    cout << "name: " << i1.getName() << ", value: ";
    cout << i1.getValue() << endl;
    //updating the value for i2
    i1.setValue(123);
    //displaying the output
    cout << "name: " << i1.getName() << ", value: ";
    cout << i1.getValue() << endl;

}

