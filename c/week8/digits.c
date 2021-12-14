//
//  digits.c
//  the code calulates a unit, tens and hundreds place of a positive three digit number.
//
//  Created by Prajanya Gupta on 05/05/21.
//

#include <stdio.h>

int main(void){
    // declaring variable and asking for input
    int num;
    printf("Please enter a three digit positive number: ");
    scanf("%d", &num);
    // validating input should not be negative and should be a 3 digit
    while (num < 0 || num/1000.00 > 1 || num/1000.00 < 0.1){
        printf("Please enter a three digit positive number: ");
        scanf("%d", &num);
    }
    // finding the ones, tens and hundreds digits by calculating mod and dividing by 10 to reduce one place
    int ones = num % 10;
    int tens = (num/10) % 10;
    int hundreds = (num/100) % 10;
    
    // printing output 
    printf("%d\n", ones);
    printf("%d\n", tens);
    printf("%d\n", hundreds);

    return 0;
}
