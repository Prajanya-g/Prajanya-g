# include<iostream>

// calling the external library
extern int sum_array(int array[], int n);

int main(void){
    // declaring a variable
    int array[5] = {4,6,2,2,8};
    // performing calculations and printing
    std::cout << "The sum is: " << sum_array(array, 5) << std::endl;
    return 0;
}