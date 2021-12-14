# include<iostream>

extern void odd_even(int vals[], int exmpl, int length);

int main(void){
    int vals[] = {10, 70, 75, 20, 31, 41, 92};
    odd_even(vals,3,7);
    odd_even(vals,0,7);
    odd_even(vals,2,7);
    return 0;
}
