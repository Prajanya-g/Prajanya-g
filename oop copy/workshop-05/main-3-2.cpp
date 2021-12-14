# include<iostream>

// importing the functions
extern int *readNumbers() ;
extern int *reverseArray(int *numbers1,int length) ;
extern void printNumbers(int *numbers,int length) ;

int main(void){
    printNumbers(reverseArray(readNumbers(),10),10);
    return 0;
}

