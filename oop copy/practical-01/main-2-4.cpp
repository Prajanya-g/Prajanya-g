# include<iostream>

// calling the external library
extern bool ascending(int array[], int n);

int main(void){
    // declaring a variable
    int array[5] = {4,6,8,9,11};
    // performing calculations and printing
    std::cout << "The array is in ascending order: " << ascending(array, 5) << std::endl;
    return 0;
}