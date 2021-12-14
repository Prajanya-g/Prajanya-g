# include<iostream>

extern void print_sevens(int *nums,int length);

int main(void){
    int number[] = {1,2,3,14,21,7,2,28,70};
    int *nums = &number[0];
    print_sevens(nums,9);
}
