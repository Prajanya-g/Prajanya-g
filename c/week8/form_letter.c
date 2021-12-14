//
//  form_letter.c
//  the code takes i user input about the users details like name, age and full time employment.
//
//  Created by Prajanya Gupta on 05/05/21.
//

#include <stdio.h>

int main(void){
    // declaring variable
    char name[21];
    int age;
    float fraction;
    // asking for the user input
    printf("Please enter your name: ");
    scanf("%20s", name);
    printf("Please enter your age in years: ");
    scanf("%d", &age);
    printf("Please enter your Full-time employment fraction(0.0 - 1.0): ");
    scanf("%f", &fraction);
    
    // validating data
    while(fraction > 1 || fraction < 0){
        printf("Please enter your Full-time employment fraction(0.0 - 1.0): ");
        scanf("%f", &fraction);
    }
    
    // displaying output
    printf("Your name is %s, you are %d years old and your employment fraction is %.1f.\n", name, age, fraction);
    return 0;
}
