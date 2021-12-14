# include<iostream>

// importing the functions
extern int *readNumbers() ;
extern bool equalsArray(int *numbers1,int *numbers2,int length) ;

int main(void){
    std::cout << equalsArray(readNumbers(),readNumbers(),10) << std::endl;
    return 0;
}
