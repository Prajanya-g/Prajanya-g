# include<iostream>

int main(void){
    int x = 42;
    int* y = &x;
    std::cout << *y+5 << std::endl;
    std::cout << *y+5-2 << std::endl;
}


