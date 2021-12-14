# include<iostream>

// calling the external library
extern int sumtwo(int array[], int secondarray[], int n);

int main(void){
    // declaring a variable
    int array[5] = {4,6,2,2,8};
    int array2[5] = {4,6,2,2,8};
    // performing calculations and printing
    std::cout << "The sum is: " << sumtwo(array, array2,5) << std::endl;
    return 0;
}