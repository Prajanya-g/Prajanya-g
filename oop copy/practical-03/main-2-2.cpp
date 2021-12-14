# include<iostream>

extern int maximum_sum(int *nums,int length) ;

int main(void){
    int number[10] = { 31, -41, 59, -26, -53, 58, 97, -93, -23, 84 };
    int *nums = &number[0];
    std::cout << maximum_sum(nums,10) << std::endl;
}
