# include<iostream>

// calling the external library
extern int minimum(int array[], int n);

int main(void){
    // declaring a variable
    int array[5] = {4,2,1,2,8};
    // performing calculations and printing
    std::cout << "The min: " << minimum(array, 5) << std::endl;
    return 0;
}