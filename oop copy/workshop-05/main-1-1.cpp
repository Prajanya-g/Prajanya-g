# include<iostream>

// importing the functions
extern int *readNumbers() ;
extern void printNumbers(int *numbers,int length) ;

int main(void){
    printNumbers(readNumbers(), 10);
    return 0;
}
