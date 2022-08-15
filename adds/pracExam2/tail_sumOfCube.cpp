#include<iostream>
int tail_sumOfCube(int n, int sum){
    if(n == 1){
        return sum+1;
    }
    sum += n*n*n;
    return tail_sumOfCube(n-1,sum);
}

int sumOfCube(int n){
    return tail_sumOfCube(n,0);
}

int main(void){
    std::cout << sumOfCube(4) << std::endl;
}
