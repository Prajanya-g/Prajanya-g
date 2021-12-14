# include<iostream>

int main(void){
    int x[] = {42,23,3,12,32,52,42};
    int* y = x;
    std::cout << *y << std::endl;
    std::cout << *(y+1) << std::endl;
}



