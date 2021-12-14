
# include<iostream>

extern double sumeven(double array[], int n);

int main(void){
    // declaring a variable
    double array[6] = {1,2,1,4,1,3};
    // performing calculations and printing
    std::cout << "The sum is: " << sumeven(array, 6) << std::endl;
    return 0;
}




