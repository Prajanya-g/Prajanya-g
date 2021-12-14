# include<iostream>

extern bool fanarray(int array[], int n);

int main(void){
    // declaring a variable
    int array[4] = {1,2,2,1};
    // performing calculations and printing
    std::cout << "The array is a fan array: " << fanarray(array, 4) << std::endl;
    return 0;
}


