/*
# include<stdio.h>
# include<string.h>
# include<stdlib.h>

int main(void){
    char input1[257];
    while (input1[0]!='#'){
        printf("Please enter the string: ");
        scanf("%256s", input1);
        int length = strlen(input1);
        char* combined = malloc(sizeof(char) * (length+1));
        combined[0]='\0'
        strcat(combined, input1);
        printf("%s\n", combined);
    }
}
*/

/*
#include <stdio.h> // use "scanf" and "printf"
#include <stdlib.h> // use "malloc"
#include <string.h> //use "strlen" and "strcat"

int main(void)
{
    int size = 1;
    char* combined = malloc(sizeof(char) * size);
    combined[0] = 0;
    
    char str[257];
    printf("Enter a string: ");
    scanf("%256s", str);
    
    while (str[0] != '#') {
        int len = strlen(str);
        size = size + len;
        char* newcombined = malloc(sizeof(char) * size);
        newcombined[0] = 0;
        
        strcat(newcombined, combined);
        strcat(newcombined, str);
        
        // release the address stores in "combined"
        // does not mean delete the variable "combined"
        free(combined);
        
        // passing the address
        combined = newcombined;
        
        printf("Enter a string: ");
        scanf("%256s", str);
    }
    
    printf("Output: %s\n", combined);
    
    free(combined);
    
    return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    // q3
    char digits[10];
    printf("Enter digits: ");
    scanf("%9s", digits);
    
    int len = strlen(digits);
    int sum = 0;
    int* digits_int = malloc(sizeof(int) * len);
    
    for (int i = 0; i < len; i++) {
        digits_int[i] = digits[i] - 48;
        sum = sum + digits_int[i];
        printf("digits_int[%d] = %d\n", i, digits_int[i]);
    }
    
    printf("sum = %d\n", sum);
    free(digits_int);
    
    // q4
    char digits_reversed[10], digits_back[10];
    int index = 0;
    
    while (sum > 0) {
        digits_reversed[index] = sum % 10 + '0';
        index++;
        sum = (sum - sum % 10) / 10;
    }
    digits_reversed[index] = 0;
    
    printf("digits_reversed = %s\n", digits_reversed);
    
    for (int i = 0; i < index; i++) {
        digits_back[i] = digits_reversed[index - 1 - i];
    }
    digits_back[index] = 0;
    
    printf("digits_back = %s\n", digits_back);
    
    return 0;
}
*/
