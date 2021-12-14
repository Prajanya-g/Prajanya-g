//
//  reverse_in_place.c
//  The code reverse prints the string.
//
//  Created by Prajanya Gupta on 013/05/21.
//
# include<stdio.h>

int main(void){
    // taking the string input
    char str[20], revStr[20];
    printf("Please enter a string: ");
    scanf("%19s", str);
    
    // count the length of the string might be smaller than 20
    int length = 0;
    while (str[length] != '\0'){
        length++;
    }

    // intrating throught each value of the new array
    for(int i = 0; i < length; i++){
        // the first element is the last element of original
        revStr[i] = str[length-1-i]; 
    }
    
    // adding the end of the string to the new array
    revStr[length] = '\0';
    printf("%s\n", revStr);
}
