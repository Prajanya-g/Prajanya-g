# include <iostream>
# include <cmath>

int binary_to_number(int binary_digits[], int number_of_digits){
    int decimal = 0;
    for(int index = 0; index < number_of_digits; index++){
        decimal += (binary_digits[index]*pow(2,number_of_digits-index-1));
    }
    return decimal;
}
