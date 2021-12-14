
# include<iostream>

extern int median(int array[], int n);

int main(void){
    // declaring a variable
    int array[5] = {6,7,5,4,3};
    // performing calculations and printing
    std::cout << "The medain: " << median(array, 5) << std::endl;
    return 0;
}


