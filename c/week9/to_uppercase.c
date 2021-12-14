//
//  to_uppercase.c
//  the code convert all the lowercase letter to uppercase and print data
//
//  Created by Prajanya Gupta on 013/05/21.
//

# include<stdio.h>

int main(void){
    //  delcalring variable and taking input
    printf("Please enter string: ");
    char name[20];
    scanf("%19s", name);
    int index = 0;
    // looping till the last value of the name
    while(name[index] != '\0'){
        // the name has a comma
        if(name[index] != ','){
            // using ascii code to convert to uppercase
            name[index] = name[index] - 32;
        }
        // incrementing index to move to next element
        index++;
    }
    // printing
    printf("%s\n", name);
    return 0;
}
