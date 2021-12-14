# include<iostream>

// calling the external library
extern void twofivenine(int array[], int n);

int main(void){
    // declaring a variable
    int array[5] = {9,2,9,2,5};
    twofivenine(array,5);
    return 0;
}