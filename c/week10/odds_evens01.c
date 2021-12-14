//
//  odds_evens01.c
//  the code asks the user for the number of inputs. Take the integer input and sort then in two dynamic array based on whether they are odd or even. The dynamic arrays are of the same size as the number of odd number and even number respectively
//
//  Created by Prajanya Gupta on 20/05/21.
//

#include <stdio.h>
#include <stdlib.h>

int main(void){
    // declaring variable size to store the size and reading input
    int size;
    printf("Please enter the number of numbers you want to enter: ");
    scanf("%d", &size);
    
    // creaitng a dynamic array
    int* num = malloc(sizeof(int)*size);
    
    //using a for loop to read the element of the array
    for(int index = 0; index < size; index++){
        printf("Please enter the %dth number: ",index);
        scanf("%d", &num[index]);
    }
    
    // creating dynaic arrays for even and odd with size and index variables
    int oddSize = 0;
    int evenSize = 0;
    int* odd;
    int* even;
    int evenIndex;
    int oddIndex;
    
    // using for loop to interatethrough values
    for(int index = 0; index < size; index++){
        // using if to check for even and odd
        if (num[index]%2==0){
            // increaseing the size of the array to add a value
            evenSize++;
            // creaitng a new array to store new values
            int* newEven = malloc(sizeof(int)*size);
            // index will be one less than size
            evenIndex = evenSize-1;
            // transferrign previous values
            for(int i = 0; i < evenIndex; i++){
                newEven[i] = even[i];
            }
            // transfering value
            newEven[evenIndex] = num[index];
            // transfering address
            even = newEven;
        }
        else{
            // increaseing the size of the array to add a value
            oddSize++;
            // creaitng a new array to store new values
            int* newOdd = malloc(sizeof(int)*size);
            // index will be one less than size
            oddIndex = oddSize-1;
            // transferrign previous values
            for(int i = 0; i < oddIndex; i++){
                newOdd[i] = odd[i];
            }
            // transfering value
            newOdd[oddIndex] = num[index];
            // transfering address
            odd = newOdd;
        }
    }
    // printing values
    printf("There are %d odd number:-", oddSize);
    for(int index = 0; index < oddSize; index++){
        printf("%d ", odd[index]);
    }
    printf("\n");
    printf("There are %d even number:-", evenSize);
    for(int index = 0; index < evenSize; index++){
        printf("%d ", even[index]);
    }
    printf("\n");
    
    free(odd);
    free(even);
    return 0;
}
