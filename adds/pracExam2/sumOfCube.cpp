#include<iostream>
int sumOfCube(int n){
    if(n == 1){
        return 1;
    }
    int sum = 0;
    sum += sumOfCube(n-1);
    sum += (n*n*n);
    return sum;
}

int main(void){
    std::cout << sumOfCube(4) << std::endl;
}