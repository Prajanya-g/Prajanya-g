//
//  temperature02.c
// The code takes user input until he/she enter -100. The starting size of the array is 5 and double each time the last element is reached. The result is printed in a reverse order
//
//  Created by Prajanya Gupta on 20/05/21.
//
#include <stdio.h>
#include <stdlib.h>

int main (void){
    // decalring size as 5 and a count variable to count the number of elements
    int size = 5;
    int count = 0;
    
    // creating a dynamic memory
    double* temperature = malloc(sizeof(double)*size);
    
    // asking for input for size
    for (int index=0; index<size;index++){
        printf("Please enter the %dth value: ", index);
        scanf("%lf", &temperature[index]);
        // ending if user enters -100
        if(temperature[index]== -100){
            count = index;
            break;
        }
        // updating count
        count = index;
    }
    // if the user wants to enter more values
    while(temperature[count] != -100){
        // update size
        size = size*2;
        // creating a new array with new size
        double* newTemperature = malloc(sizeof(double)*size);
        // adding previous values to it
        for (int index = 0; index < count+1; index++){
            newTemperature[index] = temperature[index];
        }
        // reading new values
        for (int index = count+1; index < size; index++){
            printf("Please enter the %dth value: ", index);
            scanf("%lf", &newTemperature[index]);
            // ending if user enters -100
            if(newTemperature[index]== -100){
                count = index;
                break;
            }
            // updating count
            count = index;
        }
        //clear data in old array
        free(temperature);
        // transferring address
        temperature = newTemperature;
    }
    // printing in reverse using a for loop
    for(int index = count-1; index >= 0; index--){
        printf("%.3lf ", temperature[index]);
    }
    printf("\n");
    free(temperature);
    return 0;
}
