# include<iostream>

extern void count_numbers(int array[4][4]);

int main(void){
    int array[4][4] = {
        {1,2,3,4},
        {2,3,9,4},
        {4,5,6,7},
        {5,8,5,5},
    };
    count_numbers(array);
}

