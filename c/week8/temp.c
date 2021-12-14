//
//  temp.c
//  the program converts temperature in celsius to
//  fahrenheits and displays output.
//  Created by Prajanya Gupta on 05/05/21.
//

# include <stdio.h>

int main(void){
    // decalring variables
    float celsius;
    float fahrenheit;
    // asking for user input
    printf("Please enter temperature in celsius: ");
    scanf("%f", &celsius);
    // calculating output
    fahrenheit = ((celsius*9)/5)+32;
    // displaying output
    printf("%.2f degrees Celsius is %.2f Fahrenheit\n", celsius, fahrenheit);
    return 0;
}
