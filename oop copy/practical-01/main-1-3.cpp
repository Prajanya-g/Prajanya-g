# include<iostream>

// calling the external library
extern int count(int array[], int n, int number);

int main(void){
    // declaring a variable
    int array[5] = {4,2,2,2,8};
    // performing calculations and printing
    std::cout << "The number of element equal to 2 are: " << count(array, 5, 2) << std::endl;
    return 0;
}