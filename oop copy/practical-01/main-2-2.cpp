# include<iostream>

// calling the external library
extern int maximum(int array[], int n);

int main(void){
    // declaring a variable
    int array[5] = {4,2,1,2,8};
    // performing calculations and printing
    std::cout << "The max: " << maximum(array, 5) << std::endl;
    return 0;
}