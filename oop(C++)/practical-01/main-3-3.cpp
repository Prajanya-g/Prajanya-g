
# include<iostream>

extern double weightedaverage(int array[], int n);

int main(void){
    // declaring a variable
    int array[6] = {1,2,1,4,1,3};
    // performing calculations and printing
    std::cout << "The average is: " << weightedaverage(array, 6) << std::endl;
    return 0;
}



