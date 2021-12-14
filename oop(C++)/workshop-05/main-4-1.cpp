# include<iostream>

extern int *readNumbers() ;
extern int secondSmallestSum(int *numbers,int length) ;

int main(void){
    std::cout << secondSmallestSum(readNumbers(),10) << std::endl;
    return 0;
}
