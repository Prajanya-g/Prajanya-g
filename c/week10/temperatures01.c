//
//  temperatures01.c
//  The code asks for the number of temprature user wants to enter and stores the input in a dynamic array. Then prints the stores input in reverse order
//
//  Created by Prajanya Gupta on 20/05/21.
//
#include <stdio.h>
#include <stdlib.h>

int main(void){
    // declaring variable size to store the size and reading input
    int size;
    printf("Please enter the number of temperatures you want to enter: ");
    scanf("%d", &size);
        
    // creaitng a dynamic array
    double* temperature = malloc(sizeof(double)*size);
    
    //using a for loop to read the element of the array
    for(int index = 0; index < size; index++){
        printf("Please enter the %dth element: ",index);
        scanf("%lf", &temperature[index]);
    }
    
    // printing in reverse using a for loop
    for(int index = size-1; index >= 0; index--){
        printf("%.3lf ", temperature[index]);
    }
    printf("\n");
    free(temperature);
    return 0;
}
