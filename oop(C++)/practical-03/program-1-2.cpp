#include <iostream>
using namespace std;

int main()
{
    int *ptr, a[10]={1,2,3,4,5,6,7,8,9,10};
    int *b = new int[10];

    /* address of a[0] is assigned to ptr */
    ptr = &a[0]; // ptr = a;

    // I want to copy the values in a into b; since i've declared b
    // as a dynamically allocated array,
    // I can now do pointer magic!!
    b = ptr;//It is no copying the values to the new array instead both ptr and b are pinting towards the same adress. So if any changes are made the array a then it changes in b as well. So we need to transfer the elements using a for loop

    cout << "Value of first element in b " << b[0] << endl;
    cout << "Value of second element in b " << b[1] << endl;

    a[1] = 42;
    cout << "Value of second element in b " << b[1] << endl;

    return 0;
}
