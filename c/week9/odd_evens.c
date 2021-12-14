//
//  odd_even.c
//  The seperates the odd and the even number from an integer array and prints the value
//
//  Created by Prajanya Gupta on 013/05/21.
//

# include<stdio.h>

int main(void){
    // declaring variables and array
    int num[] = {11, 3, 9, 7, 6, 10, 13, 17, 2, 8, 3};
    int even[12];
    int odd[12];
    int indexOdd = 0;
    int indexEven = 0;
    // using for lop to iterate throught each value
    for (int i = 0; i < 11; i++){
        // if condition to seperate odd and even int
        if (num[i]%2 == 1){
            // storing odd number in different array
            odd[indexOdd++] = num[i];
        }
        else{
            // storing even number in different array
            even[indexEven++] = num[i];
        }
    }
    
    // using for loop to print every value
    for (int i = 0; i < indexOdd; i++){
        printf("ODD: %d\n", odd[i]);
    }
    //using for loop to print every valur
    for (int i = 0; i < indexEven; i++){
        printf("EVEN: %d\n", even[i]);
    }
    return 0;
}
