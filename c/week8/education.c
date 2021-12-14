//
// education.c
//  the code takes input for the user and prints out the level of education attained
//
//  Created by Prajanya Gupta on 06/05/21.
//

#include <stdio.h>

int main(void){
    // declaring variables and asking for user input
    int years;
    printf("Please enter the number of year in education so far: ");
    scanf("%d", &years);
    // checking different conditions and printing output
    if (years >= 0 && years <= 7) {
        printf("you have spend %d years in eduacation and you are at Primary level education\n", years );
    }
    else if (years >= 8 && years <= 12){
        printf("you have spend %d years in eduacation and you are at Secondary level education\n", years );
    }
    else if (years >= 13){
        printf("you have spend %d years in eduacation and you are at Tertiary level education\n", years );
    }
    else{
        printf("wrong input. positive integer required\n");
    }
    return 0;
}

