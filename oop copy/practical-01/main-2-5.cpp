# include<iostream>

// calling the external library
extern bool descending(int array[], int n);

int main(void){
    // declaring a variable
    int array[5] = {4,3,2,2,2};
    // performing calculations and printing
    std::cout << "The array is in descending order: " << descending(array, 5) << std::endl;
    return 0;
}