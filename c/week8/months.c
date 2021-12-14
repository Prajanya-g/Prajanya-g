//
// months.c
//  the code takes input for the user and pritns out the coressponding month
//
//  Created by Prajanya Gupta on 06/05/21.
//

#include <stdio.h>

int main(void){
    // decalring variable and taking input
    int month;
    printf("Please enter the month in number: ");
    scanf("%d", &month);
    // storing all the months in a 2d array
    char months[12][3] ={
        "JAN",
        "FEB",
        "MAR",
        "APR",
        "MAY",
        "JUN",
        "JUL",
        "AUG",
        "SEP",
        "OCT",
        "NOV",
        "DEC"};
    //validating input
    while(month > 12 || month <=0){
        printf("Please enter the month in numer(1-12): ");
        scanf("%d", &month);
    }
    // using for loop to display each character of a row in 2D ARRAY
    for (int i=0; i < 3; i++) {
        // printing the month corresponding to the number array start with 0
        printf("%c", months[month-1][i]);
    }
    // skipping to next line 
    printf("\n");
    
    return 0;
}

