# include<iostream>

// calling the external library
extern double average(int array[], int n);

int main(void){
    // declaring a variable
    int array[5] = {4,6,2,2,8};
    // performing calculations and printing
    std::cout << "The average is: " << average(array, 0) << std::endl;
    return 0;
}