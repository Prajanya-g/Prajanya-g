# include<iostream>

// calling the external library
extern int count_even(int number);

int main(void){
    // performing calculations and printing
    std::cout << "The muber of even values between 1 - 10  is: " << count_even(10) << std::endl;
    return 0;
}