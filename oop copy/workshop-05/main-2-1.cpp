# include<iostream>

// importing the functions
extern int *readNumbers() ;
extern void hexDigits(int *numbers,int length) ;

int main(void){
    hexDigits(readNumbers(), 10);
    return 0;
}
