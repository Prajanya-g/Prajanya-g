# include<iostream>
# include<cmath>

int binary_to_number(int binary_digits[], int number_of_digits){
    int number = 0;
    for(int digit = 0; digit < number_of_digits; digit++){
        int power = number_of_digits - 1 - digit;
        int multiply = pow(2, power);
        number += (binary_digits[digit] * multiply);
    }
    return number;
}
