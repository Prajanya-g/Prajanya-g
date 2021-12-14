//
//  to_uppercase2.c
//  the code convert all the lowercase letter to uppercase and print data 
//
//  Created by Prajanya Gupta on 013/05/21.
//

# include<stdio.h>

int main(void){
    //  delcalring variable and taking input
    printf("Please enter string: ");
    char str[20];
    scanf("%19s", str);
    int index = 0;
    // looping till the last value of the str
    while(str[index] != '\0'){
        // the char in the string should be letter not symbol
        if(str[index] >= 'a' && str[index] <= 'z'){
            // using ascii code to convert to uppercase
            str[index] = str[index] - 32;
        }
        // incrementing index to move to next element
        index++;
    }
    // printing
    printf("%s\n", str);
    return 0;
}
